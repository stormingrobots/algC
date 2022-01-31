int fmoomoo2(void)
// File I/O Packet Exercise 6 for USACO
{
 FILE *fp = NULL;
 fopen_s(&fp, "censor.in", "r");
 if (fp == NULL)
  exit(EXIT_FAILURE);

 char *sen;
 sen = (char *)(malloc((1000001) * sizeof(char)));
 fgets(sen, 1000000, fp);
 int sensize = strlen(sen);
 fp++; // move to beginning of second line
 char *word; // read it from the second line
 word = (char *)(malloc((101) * sizeof(char)));
 fgets(word, 100, fp);
 int wdsize = strlen(word);
 char *sen2;
 sen2 = (char *)(malloc(sensize * sizeof(char)));
 char *p = strstr(sen, word);
 if (*p != NULL)
 {
  int n = p - sen;
  memcpy(sen2, sen, n);
  p += wdsize;
  char *q;
  q = &sen2[n];
  while (*p != NULL && p >= sen && p <= (sen + sensize))
  {
   *q = *p;
   if (memcmp(word, q - (wdsize - 1), wdsize) == 0)
    q = q - (wdsize - 1);
   else
    q++;
   p++;
  }
  *q = NULL;
 }
 fclose(fp);
 FILE *fp2 = NULL;
 fopen_s(&fp2, "censor.out", "w");
 if (fp2 == NULL)
  exit(EXIT_FAILURE);
 fprintf(fp2, "%s", sen2);
 fclose(fp2);
 return 0;
}
