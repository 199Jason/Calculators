import unittest
from calculator import addition, subtraction, multiplication, division

class TestCalculator(unittest.TestCase):

    def test_addition(self):
        self.assertEqual(addition(2, 3), 5)
        self.assertEqual(addition(-1, 1), 0)
        self.assertEqual(addition(0, 0), 0)

    def test_subtraction(self):
        self.assertEqual(subtraction(5, 3), 2)
        self.assertEqual(subtraction(-1, 1), -2)
        self.assertEqual(subtraction(0, 0), 0)

    def test_multiplication(self):
        self.assertEqual(multiplication(2, 3), 6)
        self.assertEqual(multiplication(-1, 1), -1)
        self.assertEqual(multiplication(0, 5), 0)

    def test_division(self):
        self.assertEqual(division(6, 3), 2)
        self.assertEqual(division(-6, 3), -2)
        with self.assertRaises(ValueError):
            division(5, 0)

if __name__ == "__main__":
    unittest.main()
