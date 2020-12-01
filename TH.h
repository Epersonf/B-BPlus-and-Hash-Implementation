#define TAM 101

typedef struct object_hash{
  int key;
}TA;

typedef TA* TH[TAM];

TA* TH_aloca(int key){
  TA *novo = (TA*)malloc(sizeof(TA));
  novo->key = key;
  return novo;
}

int TH_hash (int key, int n){
  return key % n;
}

int TH_tent_linear(int key, int n, int pos){
  return (TH_hash(key, n) + pos) % n;
}

void TH_inicializa(TH tab, int n){
  int i;
  for(i = 0; i < n; i++) tab[i] = NULL;
}

TA* TH_busca(TH tab, int n, int key){
  int i = 0;
  while(1){
    int h = TH_tent_linear(key, n, i++);
    if((tab[h]) && (tab[h]->key == key)) return tab[h];
    if(i == n)return NULL;
  }
}

void TH_insere(TH tab, int n, int key){
  int i = 0, achou = 0, primPosLivre, h;
  while(1){
    h = TH_tent_linear(key, n, i++);
    if(tab[h]){
      if(tab[h]->key == key){
        //update atributos
        return;
      }
    }
    else if(!achou){
      achou = 1;
      primPosLivre = h;
    }
    if(i == n)break;
  }
  tab[primPosLivre] = TH_aloca(key);
}

void TH_libera(TH tab, int n){
  int i;
  for(i = 0; i < n ;i++) if(tab[i]) free(tab[i]);
}

float TH_retira(TH tab, int n, int key){
  int i = 0, h;
  while(1){
    h = TH_tent_linear(key, n, i++);
    if(tab[h]){
      if(tab[h]->key == key){
        free(tab[h]);
        tab[h] = NULL;
        return key;
      }
    }
    if(i == n)return key;
  }
}

void TH_imprime(TH tab, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d: ", i);
    if(tab[i] != NULL) printf("%d\n", tab[i]->key);
    else printf("NULL\n");
  }
}

