#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef struct
{
  int x;
  int y;
} point_t;

typedef struct
{
  point_t* center;
  int radius;
} circle_t;

float get_circumference(circle_t *circle)
{
  return 2 * PI * circle->radius;
}

float get_area(circle_t *circle)
{
  return PI * pow(circle->radius, 2);
}

float get_distance_origin(circle_t *circle)
{
  return pow(pow(circle->center->x, 2) + pow(circle->center->y, 2), .5);
}

int main(char argc, char **argv)
{
  point_t *center = malloc(sizeof(point_t));
  int ret = strtof(argv[1], NULL);
  center->x = ret;
  ret = strtof(argv[2], NULL);
  center->y = ret;
  circle_t *circle = malloc(sizeof(circle_t));
  circle->center = center;
  ret = strtof(argv[3], NULL);
  circle->radius = ret;
  printf("The circle is located %f units from origin\n", get_distance_origin(circle));
  printf("The circumference of the circle is %f units\n", get_circumference(circle));

  return 0;
}