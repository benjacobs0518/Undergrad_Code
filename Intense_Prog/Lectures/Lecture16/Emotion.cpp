#include <iostream>
#include <string>

#include "Emotion.h"

std::ostream& operator<<(std::ostream &os, const Emotion &d) {
    os << d.get_name();
    // TODO: print out more information if you want to
    return os;
}

Emotion* EmotionFactory::GetHappy(){
  Emotion *happy = new Emotion("Happy", true, false, 1,1,1);
  return happy;
}

Emotion* EmotionFactory::GetAngry(){
  Emotion *angry = new Emotion("Angry", false, false, 0,1,1);
  return angry;
}

Emotion* EmotionFactory::GetSad(){
  Emotion *sad = new Emotion("Sad", true, false, 1,1,0);
  return sad;
}
