/*
  Mapping for the obfuscated version - still probably completely illegible even with this
  int * f = {
  [0] = charset,
  [1] = nPipes,
  [2] = colorMode,
  [3] = i loop counter,
  [4-9] = [4] = 37(WHITE), [5] = 31(RED), [6]= 32(GREEN), [7] = 33(YELLOW), [8] = 36(CYAN), [9] = 37(WHITE)
  [10-15] = [10] = "┃", [11] = "━", [12] = "┓", [13] = "┏", [14] = "┛", [15] = "┗"
  [16-31] = [16] = 0, [17] = 3, [18] = 0, [19] = 2, [20] = 4, [21] = 1, [22] = 2, [23] = 1, [24] = 0, [25] = 5, [26] = 0, [27] = 4, [28] = 5, [29] = 1, [30] = 3, [31] = 1
  [32-37] = [32] = '│', [33] = '─', [34] = '╮', [35] = '╭', [36] = '╯', [37] = '╰'
  [38-n] = pipe objects {
    i = the ith pipe object from now on
    [38 + i * 6] = x,
    [38 + 1 + i * 6] = y,
    [38 + 2 + i * 6] = color,
    [38 + 3 + i * 6] = track,
    [38 + 4 + i * 6] = direction
  }
}
  */
int main () {
  int a[] = {[0] = "┃", [1] = "━", [2] = "┓", [3] = "┏", [4] = "┛", [5] = 5};
  for (int i = 0 ; i < 6 ; i++) puts(a[i]);
}
