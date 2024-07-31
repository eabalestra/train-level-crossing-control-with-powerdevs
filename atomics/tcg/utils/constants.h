#ifndef POWERDEVS_DOCKER_CONSTANTS_H
#define POWERDEVS_DOCKER_CONSTANTS_H

/** GENERAL **/
#define INF 1.0e20

/** TRAIN **/
// states
#define FAR 1.0
#define NEAR 2.0
#define INSIDE 3.0
// output
#define APPROACH 1.0
#define IN 2.0
#define EXIT 3.0

/** CONTROLLER **/
// states
#define SC1 1.0
#define SC2 1.0
#define SC3 1.0
#define SC4 1.0
// output
#define LOWER 1.0
#define RAISE 2.0

/** GATE **/
// states
#define OPEN 1.0
#define LOWERING 1.0
#define CLOSED 1.0
#define RAISING 1.0
// output
#define DOWN 1.0
#define UP 2.0

#endif //POWERDEVS_DOCKER_CONSTANTS_H
