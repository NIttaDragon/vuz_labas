#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

double strhashing(string str)
{
  hash<string> hash_obj;
  return hash_obj(str);
}

int main()
{
  clock_t start,end;
  start = clock();
  cout<<"Наивный алгоритм \n";
  int i, j;
  int k = 0;
  string str1 = "bbbbcbcbaacbabbcaabcbcacbbaabaaababcacbbaccbcccbcbbbbcbcbbcccbaaabbcbaaaabbccacababcaabbbbabacacbbabaaaaabaabbcbcbacccbbacaccbaabbbcccccbabaaccbabbcaacbccacbbcacccbbbbabcbabacbacbacbbabbcbcccccbcacbaacacbbcacaccbabccbbacbbccccacbcbabaaccbcbbbbcaaaaabaaabaaabccaccccaaaaabbccbabbacccabbacabacaaabcabbacbbbacaabaaacbccbacaaababacacaacccacaaababbbabcaaacacbcbccaacacbbabbabcaaaacaaaabbccbacbacccccbabbbacbccbbcbaababaaabbcaacabcabbacccaccbabbcbabaaacbcbcbacccaccbbbcccababbbbabcbccaabbababaccacccbaccaabbacababaaacbcbbbcbbcacabacbcaaabbcbcaabcaaabaaacbaccacabbccababbabbccbbbccaabccaaabcbcacbbacaaccacbacacaacaacccbabbbaabccbbaccbbcabacccbaaacbbbaccacccaaaccacbcaaaccbcacbbcabaacaacaaabacbaaccacaaccbbccbabbbabcbbabbbaaccacacbcbabbacbaacbccaaacabbbcaaaccaabbcaacaaccbcaaabbcaccacbccccacabbccbbcbacccccbcacaabaaaabbabcaccabacbacbaabaaabcbbbbbabbcabbaaacabbacbbcbbcbbcccbcbbababcbacaabbaababcbbcbaaaacbbabacbcaacbcbccbabbbbaaccbbbaabbcabbabcbbcbbbaabcbcbcbcbabcaaaacbcbbbaabccbcbababbabbcbbbbaacacbcabbbabbbcbcabacbbaabbbabbcccaaacbcabbcababccabacbaacbabcbcbbcccacbaabbcaabbacaabbcabcccbabaabcccaabacababaabababcababcbbccaaccccccbcacaccbaaabaacabbcaccccabacabbaaacccbcbacbababcbaabcccbbbcbbbcabcaccaabacccacbbbbbbcbbcbbacbbbcbcaacccaaaaccccbbbcbcabaacbaaccbbabacaacccbbacabcbbccaacbcabbacbccbbccbabbcbcbbaccacaabaaacbabcacaaaacaabaacabbabbaaabcaccbbbbcaccccbabcccbabbcacbbbcbccababaaccabaabccacacbaabccbaaabcbbabaccbaaaaccbabcabbcccacacaabbcbcbaabbccaaccbcabcaaccabcbbcaaacbbabbabbbbabcabccccabbcbccabbaccbabcbacacabbbbaacbcaaccacbcbbabccccbbcbccccccbcbccaccbabbacabcbccbcccabbbcabcacaacbbabbcaaaaabccbbbacbccbaccbbbbcaaaacacbbaacbaaabbccccbccaabcbbcbcccabbbbaabbcaccaccbbabaaacbcabcbaabbbcabcaaaacccaaacaccbaccbacbcbaacbaaacaccacccabbccacabbaccaacacbcbabaabbaccaabacacaccabbaccacacbcacabcabcaaacbabaabbccbcabccbaaacccacbbabcbcbcbabbabaaccbcbbbaacaacccbbbbcbcaabaaabbbacabbcbaabccacbcaacccbbcbcaabcaaaacacaacbaabaacccacbcccacccbcabbcabccabbbacaabbbbbbacaccabcabcacbbcaccabcbaaabcacabcbbabcbcbcbcbabaccaaaacbabbacaccaacbabacccbbcaababbbcacbacbbbbbbcacccaabacccacccbbaccbbbaccacaaaabbcbccbabcabccaaaccccaccbaccbcbacbaccacbaabcbcbabcaabcacbabccccaccbbccccacbbacabcbcbcbaccaabbbbcccbacaaabbcbbcbbbbaaaccbaacccabbaaacbacacbcaaaacaabcbbababbcbaccbcbaccabacbccbcabaaaccaabbaacaaabcacbcbcabababcbabaaacbaaaacccbbcabbaaccacbbbacbbabacaaaaacacbabacccccbaacbbccbaabcbccbbababbcabbacaaabccbaaacabccaccbbccabbaaccaacbccabbcbabbacababacacbcbabcaacacbbaaacaabacbaabaabcccccccacccbcbaaababaabcbcbcacabbabbbcbccabcbbbbaacccbccbbbcabbcabbcbbbabcbbbabcbcbcbbaacaacbbabaccbcbaccaccaccaccacababbccccacaabaccaabcbcbcabbcacbaacabbcbacbccabaabbcaabbbccabbccacabbccccabbbbaccbbbccbbcccabbccbccabcbaabcababacabccccbcababbbacaccababacbcccccabcbbcccaaccbbccccccbcabcababbaccbbaccbbbbcbcbcbabbcabbbacbababccabbbacbbcccbcbcacaabbcbcbacbbabbbbbcaabbacbcbcaabbcbaacaccbaccacabcaacbbbaabbbcbcaabaabaccacabcaabcaaabacbcabccaaccabbbcccbbabcbcaaabacacaabcccbabaaabcbbcacbbcabbcbaaacabbcabbcabcababbccabbbbcbbbacccbccaacababcccaacbbaccbbbcccabacacbbccacbbcccbcabbcbbcabbabcbacabbacaaabcaabcacacccaabbcacacbabccbccbccaacaabaacbbabccababaabccaabcbcacbcbcccbbcbaccabbbbbcaaccbbbabaccccacbcabcacaaaabacbbbccaabcbabccbaaaabccabbbabcaacbbbbcabbcbccbaccbccbabbbaacccbcbcaabbcaacbcbabbcbccbabaacbcbcabcacbaccaabaacacaacbcaacbcbacacccbbbaccaababaabccbcabaaccbbcbabbbcacaccbabcccbbacaabbbccbcaabbbcabbccccbbbbcbabbbacaacbbbcbabcbacbabcabbabbcaacabacccbcabbaaabacababcabbaabaabcabacbcaaababbcbacccabcacbcaccaabcbbbbcabcbaaaacacccaabbcbccbbcaccabbbbacbcaacbacaccabccaabccbbbaacccabccbbcaaacccbabbbaacbaccccabbcccabaccaaacbcbcaabacaccbcbbaaababacbbbcbbacccccaacbaacbaaaaaacbaacacbcccaaaaccbcccbcbbaacaacbbbcaabaaccaabaacbcaaacabbccabbacacabccaccabacbccbaabbcbabbcccbbccabbbccbaaccbabccabacabbabcbacababbcbccabcbbacaccccabcacabcbaccabbbcaccbcbacaaaaaccbaabcaaacbbbaccbcaacbababbbabcbbcbcacbcbaacbababcbcaaccaccaaccbbabababaccaaaccacccabccbabbbabbcbcacaaabbbbbaaabbbcbaccbcbbcccacabbcaababccabbacbbcbaccbcacbbbacabbaacccbcbcacbababcbabaabbccaacccbbbbcbbabab";
  string str2 = "abc";
  // string str1 = "it happened about a year ago. our family bought a new car, and parents decided to celebrate it all together in the cafe. we enjoyed great food, had a conversation and a lot of fun. dad was happy and he told us many jokes, everybody laughed more and more. we played the fools and couldn’t stop.when it was time to go, dad paid and left cafe to warm up the car, and mom, her friend, my brother and i lingered in the cafe. when we went out, we realised that it was already dark outside — so we couldn’t see well. and the second thing we reailsed was the fact, that nobody can remember exactly, what our new car looks like! but mom confidently went toward the black car, that was standing nearly. «oh, dad is waiting inside, it’s ours. come on». just imagine: the company of four very noisy people, singing, talking loudly, laughing out, get into car. mum turn to driver and exclaimed cheerfully: «sasha, let’s go!»…the driver looked at us with eyes full of fear and cried out desperatly: «i am not sasha, i am egor!!! who are you?!»then we, absolutly confused and quiet, get in the right car, we told dad about it. he couldn’t drive for 5 minutes becouse of laughing.once upon a time there lived a young farmer. he worked very hard but was very poor. one day when he was far from home in the forest, an old woman looking like a peasant came up to him and said, «i know you work very hard, and all for nothing. i will give you a magic ring! it will make you rich, and your work won’t be in vain. when you turn the ring on your finger and say what you wish to have, you’ll have it at once! but there is only one wish in the ring, so think carefully before you wish.» the astonished farmer took the ring given to him by the peasant woman, and went home. in evening he came to a big city. there he went to a merchant and showed him the magic ring. when the merchant heard the astonishing story, he thought of a plan. he invited the farmer to stay in his house for the night. at night he came up to the sleeping peasant, carefully took the ring off the man’s finger, and put on another ring, which looked exactly like the one he had taken off.once upon a time there lived a young farmer. he worked very hard but was very poor. one day when he was far from home in the forest, an old woman looking like a peasant came up to him and said, «i know you work very hard, and all for nothing. i will give you a magic ring! it will make you rich, and your work won’t be in vain. when you turn the ring on your finger and say what you wish to have, you’ll have it at once! but there is only one wish in the ring, so think carefully before you wish.» the astonished farmer took the ring given to him by the peasant woman, and went home. in evening he came to a big city. there he went to a merchant and showed him the magic ring. when the merchant heard the astonishing story, he thought of a plan. he invited the farmer to stay in his house for the night. at night he came up to the sleeping peasant, carefully took the ring off the man’s finger, and put on another ring, which looked exactly like the one he had taken off. in the morning when the farmer had gone away, the merchant ran into his shop, shut the door, and said while turning the ring on his finger, «i wish to have a hundred thousand pieces of gold.» and down they came, on his head, shoulders, and arms, like a rain of gold! the frightened merchant tried to get out of the shop, but in vain. In a few minutes he was dead. when the farmer returned home, he showed the ring to his wife. «take a look at this ring,» he said. «it’s a magic ring! it will make us happy.” the astonished woman could hardly say a word «let’s try. maybe the ring will bring us more land,» she said at last. “we must be careful about our wish. don’t forget there’s only one thing that we may ask for,» he explained. «let’s better work hard for another year, and we’ll have more land.” so they worked as hard as they could and got enough money to buy the land they wished to have. then the farmer’s wife thought of asking for a cow and a horse. they discussed the matter more than once. “my good wife”, — said the farmer, — “we shall get a horse and a cow without the ring.” they went on working hard for a whole year and again bought the things they wished to have. «what happy people we are!» said the farmer. “i don’t understand you,» answered his wife angrily. «there’s nothing in the world that we can’t have, and still we spend days and nights working as hard as before, because you don’t want to use your magic ring!” thirty, then forty years had gone by. the farmer and his wife had grown old. their hair became as white as snow. they were happy and had everything they wanted. their ring was still there. although it was not a magic ring, it had made them happy. for you see, my dear friends, a poor thing in good hands is better than a fine thing in bad hands.";
  // string str2 = "in";
  for(i = 0; i<str1.length()+1; i++)
  {
    for(j = 0; j<str2.length()+1; j++)
      if (str1[i+j] != str2[j])
        break;
    if (j == str2.length())
    {
      // cout<<"Начало подстроки: "<<i<<endl;
      k++;
    }
  }
  if (k==0) cout<<"Подстрока не найдена \n";
  end = clock();
  cout<<end-start<<endl;

  start = clock();
  cout<<"Второй алгоритм \n";
  double hash1, hash2;  //2-й алгоритм
  string str;
  i = 0; k = 0; int l;
  hash2 = strhashing(str2);
  while (i < str1.length()-str2.length()+1)
  {
    str.clear();
    str.append(str1,i,str2.length());
    hash1 = strhashing(str);
    if (hash1 == hash2)
    {
      l = 0;
      for (int j = 0; j < str2.length(); j++)
        if (str[j] == str2[j]) l++;
      // if (l == str2.length())
      //   cout<<"Начало подстроки: "<<i<<endl;
      k++;
    }
    i++;
  }
  if(k == 0)
    cout<<"Строка не содержит подстроку \n";
  end = clock();
  cout<<end-start<<endl;

  start = clock();
  cout<<"Третий алгоритм \n";
  int *a = new int [str2.length()]; //3-й алгоритм
  for (i = 0; i < str2.length(); i++)
    a[i] = 0;
  i = 1; j = 0;
  while (i < str2.length())
  {
    if(str2[i] != str2[j])
    {
      if(j == 0)
      {
        a[i] = 0;
        i++;
      }
      else j = a[j-1];
    }
    else
    {
      a[i] = j+1;
      i++; j++;
    }
  }
  i = 0; j = 0;
  while (i < str1.length()-str2.length()+1)
  {
    if(str1[i] == str2[j])
    {
      i++; j++;
      // if(j == str2.length()) cout<<"Начало подстроки: "<<i-str2.length()<<endl;
    }
    else
    {
      if(j > 0) j = a[j-1];
      else i++;
    }
  }
  end = clock();
  cout<<end-start<<endl;
}
