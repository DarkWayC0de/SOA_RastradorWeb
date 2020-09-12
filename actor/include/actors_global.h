//
// Created by darkwayc0de on 6/6/20.
//

#ifndef ACTOR_ACTORS_GLOBAL_H
#define ACTOR_ACTORS_GLOBAL_H

#if __GNUC__ >= 4
  #define EXPORTED __attribute__ ((visibility ("default")))
  #define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
#else
    #define EXPORTED
    #define NOT_EXPORTED
#endif

#endif //ACTOR_ACTORS_GLOBAL_H
