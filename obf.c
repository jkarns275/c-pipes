#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#define I() (rand()&1)
int R=40;
int C=80;
int * f;
int gc() {
  if (f[2] == 0) return f[4 + rand() % 6];
  return 37;
}

void rp(int* p) {
  if (I()) {
    if (I()) {
      p[1] = 0;
      p[4] = 2;
    } else {
      p[1] = R - 3;
      p[4] = 0;
    }
    p[0] = rand() % (C-1);
  } else {
    if (I()) {
      p[0] = 0;
      p[4] = 1;
    } else {
      p[0] = C - 2;
      p[4] = 3;
    }
    p[1] = rand() % (R-1);
  }
  p[3] = 2 + (rand() % 8);
  p[2] = gc();
}

void tp(int* p) {
  p[5] = p[4];
  switch(p[4]) {
  case 0:
  case 2:
    if (I()) p[4] = 3;
    else if (I()) p[4] = 1;
    break;
  case 3:
  case 1:
    if (I()) p[4] = 0;
    else if (I()) p[4] =2;
  }
  p[3] = 2 + (rand() % 8);
}

void pp(int* p) {
  char * c = (f[f[4 * p[5] + p[4] + 16] + 10]);
  printf("\033[%d;%dH\033[%dm%s", p[1], p[0], p[2], c);
  p[5] = p[4];
}

void up(int* p) {
  p[3]--;
  if (p[3] <= 0) {
    tp(p);
  } else {
    switch(p[4]) {
    case 0:
      p[1] -= 1;
      break;
    case 2:
      p[1] += 1;
      break;
    case 3:
      p[0] -= 1;
      break;
    case 1:
      p[0] += 1;
    }
    if (p[0] <= 0 | p[0] >= C |
        p[1] <= 0 | p[1] >= R) {
      rp(p);
    }
  }
  pp(p); 
}

void ha(int argc, char** args) {
  for (f[3] = 0 ; f[3] < argc ; f[3] += 1) {
    if (strcmp("-c", args[f[3]]) == 0 | strcmp("-C", args[f[3]]) == 0) {
      if (f[3] + 1 < argc) {
        f[0] = atoi(args[f[3] + 1]);
      } else {
        printf("Usage: -c [0-4]");
        exit(0);
      }
    } else if (strcmp("-n", args[f[3]]) == 0 | strcmp("-N", args[f[3]]) == 0) {
      if (f[3] + 1 < argc) {
        f[1] = atoi(args[f[3] + 1]);
        if (f[1] < 1) f[1] = 1;
      } else {
        printf("Usage: -n [number of pipes]");
        exit(0);
      }
    } else if (strcmp("-h", args[f[3]]) == 0 | strcmp("-H", args[f[3]]) == 0) {
      if (f[3] + 1 < argc) {
        R = atoi(args[f[3] + 1]);
        if (R < 5 || R > 240) R = 40;
      } else {
        printf("Usage: -h [height]");
        exit(0);
      }
  } else if (strcmp("-w", args[f[3]]) == 0 | strcmp("-W", args[f[3]]) == 0) {
      if (f[3] + 1 < argc) {
        C = atoi(args[f[3] + 1]);
        if (C < 10 || C > 250) C = 60;
      } else {
        exit(0);
      }
    }
  }
}

int main(int argc, char** args) {
  f = (int*)malloc(sizeof(int) * 4);
  f[0] = 0,
  f[1] = 1,
  f[2] = 0,
  f[3] = 0;
  ha(argc, args);
  f = realloc(f, sizeof(int) * (f[1] * 6 + 38));
  f[4] = 37, f[5] = 31, f[6]= 32, f[7] = 33, f[8] = 36, f[9] = 37,
    f[10] = "┃", f[11] = "━", f[12] = "┓", f[13] = "┏", f[14] = "┛", f[15] = "┗",
    f[16] = 0, f[17] = 3, f[18] = 0, f[19] = 2, f[20] = 4, f[21] = 1, f[22] = 2, f[23] = 1, f[24] = 0, f[25] = 5,
    f[26] = 0, f[27] = 4, f[28] = 5, f[29] = 1, f[30] = 3, f[31] = 1,
    f[32] = "│", f[33] = "─",f[34] = "╮", f[35] = "╭", f[36] = "╯", f[37] = "╰";
  for (f[3] = 0 ; f[3] < f[1] ; f[3]++) rp(f + 38 + f[3] * 6);

  

  srand(time(0));
  struct timespec t1, t2;
  t1.tv_sec = 0;
  t1.tv_nsec = 150 * 200000;
  printf("\033[H\033[J");
  while (1) {
    for (f[3] = 0 ; f[3] < f[1] ; f[3]++) up(f + 38 + f[3] * 6);
    nanosleep(&t1, &t2);
    //movecursor(0, 0);
    //printf("x: %d ; y: %d ; track: %d", pipes[0].x, pipes[0].y, pipes[0].track);
    fflush(stdout);
  }

  free(f);
}
