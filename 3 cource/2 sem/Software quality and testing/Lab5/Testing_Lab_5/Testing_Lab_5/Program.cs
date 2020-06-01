using System;
using System.Collections.Generic;

namespace Testing_Lab_5
{
    public static class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();

            Dictionary<char, int> sHash = Methods.AlphabetHash(s);

            bool answer = Methods.AreCharCountsEqual(sHash);

            if (answer)
            {
                Console.WriteLine("YES");
            }
            else
            {
                answer = Methods.CharCountsWithinOne(sHash);

                if (answer)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
            }
        }
    }

    public static class Methods
    {
        // Считает количество букв в строке
        public static Dictionary<char, int> AlphabetHash(string s)
        {
            Dictionary<char, int> Hash = new Dictionary<char, int>();

            for (int i = 97; i <= 122; i++)
            {
                Hash.Add((char)i, 0);
            }

            for (int i = 0; i < s.Length; i++)
            {
                Hash[s[i]]++;
            }

            return Hash;
        }
        
        public static bool AreCharCountsEqual(Dictionary<char, int> Hash)
        {
            bool answer = false;
            int countAllChars = 0;
            int countCharsNumber = 0;

            for (int i = 97; i <= 122; i++)
            {
                for (int j = 97; j <= 122; j++)
                {
                    if (Hash[(char)i] > 0 && Hash[(char)j] > 0)
                    {
                        countAllChars++;
                        if (Hash[(char)i] == Hash[(char)j])
                        {
                            countCharsNumber++;
                        }
                    }
                }
                if (countCharsNumber == countAllChars && countCharsNumber > 0)
                {
                    answer = true;
                    break;
                }
                else
                {
                    countCharsNumber = 0;
                    countAllChars = 0;
                }
            }
            return answer;
        }
        
        public static bool CharCountsWithinOne(Dictionary<char, int> Hash)
        {
            bool answer = false;
            int count = 0;
            int count1 = 0;
            for (int i = 97; i <= 122; i++)
            {
                Dictionary<char, int> CheckHash = new Dictionary<char, int>(Hash);

                CheckHash[(char)i]--;

                for (int j = 97; j <= 122; j++)
                {
                    for (int k = 97; k <= 122; k++)
                    {
                        if (CheckHash[(char)j] > 0 && CheckHash[(char)k] > 0)
                        {
                            if (CheckHash[(char)j] == CheckHash[(char)k])
                            {
                                count++;
                            }
                            count1++;
                        }
                    }
                    if (count == count1 && count > 0)
                    {
                        answer = true;
                        break;
                    }
                    else
                    {
                        count = 0;
                        count1 = 0;
                    }
                }
                if (answer)
                {
                    break;
                }
            }
            return answer;
        }
    }
}
