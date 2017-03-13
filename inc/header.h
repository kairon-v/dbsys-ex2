#ifndef HELPERS_H_
#define HELPERS_H_

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define BRED  "\033[1m\033[31m"
#define BGRN  "\033[1m\033[32m"
#define BYEL  "\033[1m\033[33m"
#define BBLU  "\033[1m\033[34m"
#define BMAG  "\033[1m\033[35m"
#define BCYN  "\033[1m\033[36m"
#define BWHT  "\033[1m\033[37m"
#define RESET "\x1B[0m"

/* Declaração de funções auxiliares */
extern void clear();
extern void clearbuffer();
extern void clearline();
extern void lineup();
extern void get_string(char *string, int length);

// size for owner fields
#define OWNER_NAME_LENGTH 31
#define OWNER_CPF_LENGTH 16
#define OWNER_ADDR_LENGTH 31
#define OWNER_NBHD_LENGTH 16
#define OWNER_ZPCD_LENGTH 11
#define OWNER_CITY_LENGTH 20
#define OWNER_STAT_LENGTH 3

// sizes for cars fields
#define CAR_MANU_LENGTH 21
#define CAR_MODE_LENGTH 21
#define CAR_RPLT_LENGTH 10
#define CAR_RENA_LENGTH 14


// options for view_add_car - controller_car
#define CONFIRM_ADD_CAR 'a'
#define CANCEL_ADD_CAR 'b'

// options for view_add_owner - controller_owner
#define CONFIRM_ADD_OWNER 'a'
#define CANCEL_ADD_OWNER 'b'

// options for view_car - controller_car
#define EDIT_CAR 'a'
#define CANCEL_EDIT_CAR 'b'
#define DELETE_CAR 'b'

// options for view_edit_car - controller_edit_car
#define CONFIRM_EDIT_CAR 'a'
#define CANCEL_EDIT_CAR 'b'

// options for view_edit_owner - controller_edit_owner
#define CONFIRM_EDIT_OWNER 'a'
#define CANCEL_EDIT_OWNER 'b'

// options for view_delete_car - controller_delete_car
#define CONFIRM_DELETE_CAR 'a'
#define CANCEL_DELETE_CAR 'b'

// options for view_delete_owner - controller_delete_owner
#define CONFIRM_DELETE_OWNER 'a'
#define CANCEL_DELETE_OWNER 'b'


// options for view_edit_owner - controller_edit_owner
#define CONFIRM_EDIT_OWNER 'a'

// options for view_home
#define ADD_OWNER 'a'
#define SEARCH_OWNER 'b'
#define EXIT 'x'

// options for view_owner - controller_owner
#define EDIT_OWNER 'a'
#define DELETE_OWNER 'b'
#define ADD_CAR 'c'
#define SEARCH_CAR 'd'
#define BACK_TO_HOME 'v'
#define BACK_TO_OWNER 'v'

// options for view_search_car - controller_search_car
// options for view_search_owner - controller_search_owner
#define CONFIRM_SEARCH 'a'
#define CANCEL_SEARCH 'b'

// options for view_search_car_not_found - controller_search_car_not_found
// options for view_search_owner_not_found - controller_search_owner_not_found
#define NEW_SEARCH 'a'

#define OWNERS_FILE "database/owners.dat"
#define OWNERS_FILE_TEMP "database/owners_temp.dat"
#define CARS_FILE "database/cars.dat"
#define CARS_FILE_TEMP "database/cars_temp.dat"

typedef struct _owner owner;
typedef struct _car car;

typedef struct _node_owner node_owner;
typedef struct _header_owners header_owners;
typedef struct _node_car node_car;
typedef struct _header_cars header_cars;

extern void controller_add_car();
extern void controller_add_owner();
extern void controller_car();
extern void controller_delete_car();
extern void controller_delete_owner();
extern void controller_edit_car();
extern void controller_edit_owner();
extern void controller_home();
extern void controller_owner();
extern void controller_search_car();
extern void controller_search_car_not_found();
extern void controller_search_owner();
extern void controller_search_owner_not_found();

extern void view_home();
extern void view_owner();
extern void view_car();
extern void view_add_owner();
extern void view_edit_owner();
extern void view_delete_owner();
extern void view_search_owner();
extern void view_delete_car();
extern void view_search_car();
extern void view_search_owner_not_found();
extern void view_search_car_not_found();
extern void view_add_car();
extern void view_edit_car();
extern void view_delete_car();
extern void view_exit();

extern void insert_owner(owner * data);
extern void delete_owner();

extern void insert_car(car * data);
extern void delete_car();

extern void create_lists();
extern void save_owners();
extern void save_cars();
extern void load_owners();
extern void load_cars();

extern node_owner * search_owner(const char* cpf);
extern node_car * search_car(const char* registration_plate);

car * add_car;
owner * add_owner;
car * editing_car;
owner * editing_owner;
node_car * viewing_car;
node_owner * viewing_owner;
header_cars * cars;
header_owners * owners;

char cpf[OWNER_CPF_LENGTH];
char registration_plate[CAR_RPLT_LENGTH];

#endif
