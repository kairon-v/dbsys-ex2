
/* Limpa a tela */
void clear(){
  printf("\e[1;1H\e[2J");
}

/* Limpa o buffer do teclado */
void clearbuffer(){
  while((getchar())!='\n');
}

/* Limpa a linha onde o cursor está */
void clearline(){
  printf("\33[2K\r");
}

/* Sobe o cursor para linha antecedente */
void lineup(){
  printf("\033[A");
}

void linedown(){
  printf("\033[B");
}

/* Receber uma string */
void get_string(char *string, int length){
  int i = 0;
  while((string[i] = getchar())!='\n'){
    i++;
  }
  string[i] = '\0';

}
