// controller_add_car
// controller_add_owner
// controller_car
// controller_home
// controller_delete_car
// controller_delete_owner
// controller_edit_car
// controller_edit_owner
// controller_search_car
// controller_search_car_not_found
// controller_search_owner
// controller_search_owner_not_found

void controller_add_car(){
  add_car = malloc(sizeof(car));
  add_car->id = cars->last_id;
  add_car->owner = viewing_owner->data.id;

  // render view
  view_add_car();

  switch(get_option()){
    case CONFIRM_ADD_CAR:
      insert_car(add_car);
      free(add_car);
      controller_owner();
      break;

    case CANCEL_ADD_CAR:
      free(add_car);
      controller_owner();
      break;

    default:
      free(add_car);
      controller_home();
    }
}

void controller_add_owner(){
  add_owner = malloc(sizeof(owner));
  add_owner->id = owners->last_id;

  // render view
  view_add_owner();

  switch(get_option()){
    case CONFIRM_ADD_CAR:
      insert_owner(add_owner);
      free(add_owner);
      controller_owner();
      break;

    default:
      free(add_owner);
      controller_home();
    }
}

void controller_car(){

  // render view
  view_car();

  switch(get_option()){
    case EDIT_CAR:
      controller_edit_car();
      break;

    case DELETE_CAR:
      controller_delete_car();
      break;

    default:
      controller_owner();
  }
}

void controller_delete_car(){

  // render view
  view_delete_car();

  switch(get_option()){
    case CONFIRM_DELETE_CAR:
      delete_car();
      controller_owner();
      break;

    default:
      controller_car();
  }
}

void controller_delete_owner(){

  // render view
  view_delete_owner();

  switch(get_option()){
    case CONFIRM_DELETE_OWNER:
      delete_owner();
      controller_home();
      break;
    default:
      controller_owner();
    }
}

void controller_edit_car(){
  editing_car = malloc(sizeof(car));

  // render view
  view_edit_car();

  if(get_option() == CONFIRM_EDIT_CAR){
    edit_car(editing_car);
  }
  free(editing_car);
  controller_car();
}

void controller_edit_owner(){
  editing_owner = malloc(sizeof(owner));
  // render view
  view_edit_owner();

  if(get_option() == CONFIRM_EDIT_OWNER){
    edit_owner(editing_owner);
  }
  free(editing_owner);
  controller_owner();
}

void controller_home(){

  // render view
  view_home();

  switch(get_option()){
    case ADD_OWNER:
      controller_add_owner();
      break;

    case SEARCH_OWNER:
      controller_search_owner();
      break;

    case EXIT:
      // render view_exit
      view_exit();
      exit(0);
      break;

    default:
      controller_home();
  }
}

void controller_owner(){

  // render view
  view_owner();

  switch(get_option()){
    case EDIT_OWNER:
      controller_edit_owner();
      break;

    case DELETE_OWNER:
      controller_delete_owner();
      break;

    case ADD_CAR:
      controller_add_car();
      break;

    case SEARCH_CAR:
      controller_search_car();
      break;

    default:
      controller_home();
    }
}

void controller_search_car(){
  // render view
  view_search_car();

  switch(get_option()) {
    case CONFIRM_SEARCH:
      viewing_car = search_car(registration_plate);
      if(viewing_car){
        controller_car();
      }
      else {
        controller_search_car_not_found();
      }

      break;

    default:
      controller_owner();
  }
}

void controller_search_car_not_found(){

  // render view
  view_search_car_not_found();

  switch(get_option()) {
    case NEW_SEARCH:
      controller_search_car();
      break;

    default:
      controller_owner();

  }

}

void controller_search_owner(){

  // render view
  view_search_owner();

  switch(get_option()) {
    case CONFIRM_SEARCH:
      viewing_owner = search_owner(cpf);
      if(viewing_owner) {
        controller_owner();
      }
      else {
        controller_search_owner_not_found();
      }

      break;

    default:
      controller_home();

  }

}

void controller_search_owner_not_found(){

  // render view
  view_search_owner_not_found();

  switch(get_option()) {
    case NEW_SEARCH:
      controller_search_owner();
      break;

    default:
      controller_home();

  }

}
