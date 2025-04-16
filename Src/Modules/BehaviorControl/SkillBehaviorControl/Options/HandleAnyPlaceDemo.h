option(HandleAnyPlaceDemo)
{
  // common_transition
  // {
  //   switch(theLibDemo.demoGameState)
  //   {
  //     case LibDemo::soccer:
  //       if(theFieldBall.ballWasSeen(4000)){
  //         goto playing;
  //       }
  //       else{
  //         goto searching;
  //       }
  //     case LibDemo::talking:
  //       goto talking;
  //     case LibDemo::waving:
  //       goto waving;
  //     case LibDemo::posing:
  //       goto posing;
  //     default:
  //       FAIL("Unknown demo game state.");
  //   }
  //   // if(state_time>2){
  //   //     goto falling;
  //   //     }
  // }

  initial_state(initial)
  {
    transition{
      if(theFieldBall.ballWasSeen(4000))
      {
        goto playing;
      }
      else if(theLibDemo.demoGameState==LibDemo::waving){
        goto waving;
      }
      else{
          goto searching;
        }
    }
    action{

    }
  }

  state(playing)
  {
    transition
    {
      if(state_time>5000){
        goto falling;
        }
    }
    action
    {
      theDemoGoToBallAndKickSkill();
      theLookAtBallSkill();
      // theWalkToBallAndKickSkill({
      //                          .kickType = KickInfo::forwardFastRightLong});
    }
  }

  state(falling)
  {
    transition{
      if(!theFieldBall.ballWasSeen(4000)){
      goto searching;
    }
    }
    action
    {
      // theDemoGoToBallAndKickSkill();
      theWalkToBallAndKickSkill({
                               .kickType = KickInfo::forwardFastRightLong});
      theLookAtBallSkill();                       
    }
  }

  state(searching)
  {
    transition{
      if(theFieldBall.ballWasSeen(4000)){
      goto playing;
    }
    }
    action
    {
      theDemoSearchForBallSkill();
    }
  }
    state(waving)
  {
    action
    {
      theDemoWaveSkill();
    }
  }
  }
//   state(talking)
//   {
//     action
//     {
//       theDemoTalkSkill();
//     }
//   }



//   state(posing)
//   {
//     action
//     {
//       theOptionalImageRequest.sendImage = true;
//       theDemoPoseSkill();
//     }
//   }

