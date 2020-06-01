using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;


namespace Testing_Lab_5.Tests
{
    [TestClass]
    public class ProgramTests
    {
        [TestMethod]
        public void AlphabetHash_OneChar_OneChar()
        {
            string s = "a";
            Dictionary<char, int> expectedHash = new Dictionary<char, int>();
            for (int i = 97; i <= 122; i++)
            {
                expectedHash.Add((char)i, 0);
            }
            expectedHash[s[0]]++;

            Dictionary<char, int> actualHash = Methods.AlphabetHash(s);
           
            CollectionAssert.AreEqual(expectedHash, actualHash);
        }

        [TestMethod]
        public void AlphabetHash_nChar_nChar()
        {
            string s = "aabbcc";
            Dictionary<char, int> expectedHash = new Dictionary<char, int>();
            for (int i = 97; i <= 122; i++)
            {
                expectedHash.Add((char)i, 0);
            }
            expectedHash['a'] = 2;
            expectedHash['b'] = 2;
            expectedHash['c'] = 2;

            Dictionary<char, int> actualHash = Methods.AlphabetHash(s);

            CollectionAssert.AreEqual(expectedHash, actualHash);
        }

        [TestMethod]
        public void AreCharCountsEqual_OneChar_True()
        {
            string s = "a";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharInOrder_True()
        {
            string s = "aabbccdd";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharNotInOrder_True()
        {
            string s = "abcddcba";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharRandomOrder_True()
        {
            string s = "anrsonoasr";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharInOrder_False()
        {
            string s = "aaabccccdddd";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = false;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharNotInOrder_False()
        {
            string s = "abcdddccccbba";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = false;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void AreCharCountsEqual_nCharRandomOrder_False()
        {
            string s = "anrsonooaaaar";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = false;

            bool actual = Methods.AreCharCountsEqual(hash);

            Assert.AreEqual(expected, actual);
            
        }

        [TestMethod]
        public void CharCountsWithinOne_nChar_True()
        {
            string s = "aabbccc";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.CharCountsWithinOne(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void CharCountsWithinOne_nCharRandomOrder_True()
        {
            string s = "aacccbb";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = true;

            bool actual = Methods.CharCountsWithinOne(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void CharCountsWithinOne_nChar_False()
        {
            string s = "aabbcccc";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = false;

            bool actual = Methods.CharCountsWithinOne(hash);

            Assert.AreEqual(expected, actual);
        }

        [TestMethod]
        public void CharCountsWithinOne_nCharRandomOrder_False()
        {
            string s = "aaccccbb";
            Dictionary<char, int> hash = Methods.AlphabetHash(s);
            bool expected = false;

            bool actual = Methods.CharCountsWithinOne(hash);

            Assert.AreEqual(expected, actual);
        }
    }
}
