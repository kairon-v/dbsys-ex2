/* Este arquivo contém as funções de estrutura de dados */

// linked list for the owners
struct _node_owner {
  owner data;
  node_owner * next;
  node_owner * prev;
};

// header of the linked list for the owners
struct _header_owners {
  int size;
  int last_id;
  node_owner * start;
  node_owner * end;
};


// linked list for the cars
struct _node_car {
  car data;
  node_car * next;
  node_car * prev;
};

// header of the linked list for the cars
struct _header_cars {
  int size;
  int last_id;
  node_car * start;
  node_car * end;
};


void create_lists(){
  owners = malloc(sizeof(header_owners*));
  owners->size = 0;
  owners->last_id = 0;
  owners->start = NULL;
  owners->end = NULL;

  cars = malloc(sizeof(header_cars*));
  cars->size = 0;
  cars->last_id = 0;
  cars->start = NULL;
  cars->end = NULL;

}

void insert_owner(owner * data){
  node_owner * new = malloc(sizeof(node_owner));
  if(new == NULL){
    printf("FALHA MEMORIA\n");
    return;
  }

  new->data = *data;

  if(owners->size == 0){
    owners->start = new;
    new->prev = NULL;
  }
  else {
    new->prev = owners->end;
    owners->end->next = new;
  }
  new->next = NULL;
  owners->end = new;
  owners->size++;
  owners->last_id++;

  viewing_owner = owners->end;

}

void insert_car(car * data){
  node_car * new = malloc(sizeof(node_car));
  new->data = *data;

  if(cars->size == 0){
    cars->start = new;
    new->prev = NULL;
  }
  else {
    new->prev = cars->end;
    cars->end->next = new;
  }
  new->next = NULL;
  cars->end = new;
  cars->size++;
  cars->last_id++;
}


node_owner * search_owner(const char* cpf){
  node_owner * each;
  for(each = owners->start; each != NULL; each=each->next){
    if(strcmp(cpf, each->data.cpf) == 0){
      return each;
    }
  }
  return NULL;
}

node_car * search_car(const char* registration_plate){
  node_car * each;
  for(each = cars->start; each != NULL; each=each->next){
    if((viewing_owner->data.id == each->data.owner) && strcmp(registration_plate, each->data.registration_plate) == 0){
      return each;
    }
  }
  return NULL;
}

void delete_owner(){
  if(viewing_owner == owners->start){
      viewing_owner->next->prev = NULL;
      owners->start = viewing_owner->next;
  }
  else if(viewing_owner == owners->end){
      viewing_owner->prev->next = NULL;
      owners->end = viewing_owner->prev;
  }
  else {
      viewing_owner->next->prev = viewing_owner->prev;
      viewing_owner->prev->next = viewing_owner->next;
  }
  free(viewing_owner);
  viewing_owner = NULL;
  owners->size--;
}

void delete_car(){
  if(viewing_car == cars->start){
    viewing_car->next->prev = NULL;
    cars->start = viewing_car->next;
  }
  else if(viewing_car == cars->end){
    viewing_car->prev->next = NULL;
    cars->end = viewing_car->prev;
  }
  else {
    viewing_car->next->prev = viewing_car->prev;
    viewing_car->prev->next = viewing_car->next;
  }
  exit(0);
  free(viewing_car);
  viewing_car = NULL;
  cars->size--;
}

void edit_owner(owner * data){
  strcpy(data->name, viewing_owner->data.name);
  strcpy(data->cpf, viewing_owner->data.cpf);
  strcpy(data->address, viewing_owner->data.address);
  strcpy(data->neighborhood, viewing_owner->data.neighborhood);
  strcpy(data->zip_code, viewing_owner->data.zip_code);
  strcpy(data->city, viewing_owner->data.city);
  strcpy(data->state, viewing_owner->data.state);
}

void edit_car(car * data){
  strcpy(data->manufacturer, viewing_car->data.manufacturer);
  strcpy(data->model, viewing_car->data.model);
  strcpy(data->registration_plate, viewing_car->data.registration_plate);
  strcpy(data->renavam, viewing_car->data.renavam);
}
