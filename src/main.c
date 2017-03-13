#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/header.h"
#include "helpers.c"
#include "system.c"
#include "data.c"
#include "controllers.c"
#include "views.c"
#include "models.c"



int main(void)
{
  // create linked linkes
  create_lists();
  // load data
  load_owners();
  load_cars();
  controller_home();
  return 0;
}
