/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 *   Description: By using |, we have (0,1)->1, (1,0)->1, which is the opposite
 *                of what we are expecting from &, thus we add ~ at the outer
 *                layer. Now we have (0,0)->1, (1,1)->0, which is again the
 *                opposite of what we expect for &, thus we add another ~ at the
 *                front of x and y thus fixing the problem while not affecting
 *                (0,1) and (1,0).
 */
int bitAnd(int x, int y) {
  return ~((~x) | (~y));
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 *   Description: We are taking advantage of the fact that the parameter is a
 *                signed integer. From the tip of the spec, right shifting a
 *                signed quantity will fill with sign bits, thus if the most
 *                significant bit is 1, then all will be 1, if 0 then all 0.
 *                Thus we make the least significant bit most significant by
 *                left shifting 31, then right shifting 31 again to copy that
 *                that bit to all positions.
 */
int copyLSB(int x) {
  return (x << 31) >> 31;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *   Description: Rightshifting the wanted byte to the LSB, then extract the
 *                bits by associating with 0....011111111 using & operator.
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & (~(~0 << 8));
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 *   Description: We use ^ operator for 2 integers. If every bits are same,
 *                result will be 0. Then use logical NOT so value 0 will
 *                return 1.
 */
int isEqual(int x, int y) {
  return !(x ^ y);
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 *   Description: We start from 0x7fffffff and 0xffffffe, which are 01...1 and
 *                1...10. 01...1 is the right mask and 1...10 is the left mask.
 *                We right shift the right mask to the lowbit, and left shift
 *                the left mask to the highbit. When we add them by | operator,
 *                intersected section will be 0 while other bits will be 1.
 *                Lastly, we need to bitwise negation to preduce the correct
 *                format.
 */
int bitMask(int highbit, int lowbit) {
  // right shifting the right mask
  int shiftedRMask = ~(1 << 31) >> (31 + (~lowbit + 1));
  // left shifting the left mask
  int shiftedLMask = ~1 << highbit;
  return ~( shiftedRMask | shiftedLMask );
}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 *   Description: We seperate and preserve each byte by right shifting it to
 *                the LSB and associate it with 0xff using & operator. Next
 *                step we left shift each byte to the corresponding position
 *                and adding up bytes from LSB to MSB, using | operator.
 */
int reverseBytes(int x) {
  return (0xff & (x >> 24)) | ((0xff & (x >> 16)) << 8) | ((0xff & (x >> 8)) << 16) | ((0xff & x) << 24);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 *   Description: Key observation is that 0 and -0 have same MSB while nonzero
 *                and negative nonzero have different MSB. Again, taking
 *                the advantage of the fact that the parameter is signed integer
 *                , we use | operator to make 0 produces 0 MSB and nonzero
 *                produces 1 MSB, then by right shifting it, we have either
 *                (0 -> 0) or (1 -> -1). Then all we need to do is adding 1.
 */
int bang(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *   Description: Key observation is that a signed integer and its negation,
 *                when looking their bits on corresponding positions, both
 *                contain 1 at the LSB. Thus & operator will do the masking.
 */
int leastBitPos(int x) {
  return x & (~x + 1);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 *   Description: We follow the way we negate 1 using two's complement notation.
 */
int minusOne(void) {
  return ~1 + 1;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 *   Description: To return 0x7fffffff, we want 0111 1111....1 (31 1s). We first
 *                get 1000 0000...0 (31 0s), then use ~ operator.
 */
int tmax(void) {
  return ~(1 << 31);
  //return 2;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 *   Description: Key observation is that if x can be represented as an n-bit,
 *                then bits that are at the left of the rightmost n-bits
 *                (extraBits) will have no effect to x. Thus (x << extraBits) >>
 *                extraBits should be the same as x if x can be represented.
 *                those that are different than x, thus cannot be represented
 *                as an n-bit.
 */
int fitsBits(int x, int n) {
  int extraBits = 33 + (~n);
  return !( ((x << extraBits) >> extraBits) + (~x + 1));
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 *   Description: Overflow occurs when negative integers produce positive
 *                integer and positive integers produce negative integer.
 *                Thus we can produce a truth table as follows
 *                (sx, sy, ssum) = addOK: (0,0,0)=1, (1,1,1)=1, (0,1,0)=1
 *                (0,1,1)=1, (1,0,0)=1, (1,0,1)=1, (0,0,1)=0, (1,1,0)=0.
 *                Thus we can design a logic as the return expression.
 */
int addOK(int x, int y) {
  int sx = x >> 31;
  int sy = y >> 31;
  int ssum = (x + y) >> 31;
  return !!(sx ^ sy) | !(sy ^ ssum);
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 *   Description: If x > y, then x - y - 1 >= 0, which means sign bit of (x-y-1)
 *                cannot be 1. Thus value is true if x > y. Next we have four
 *                cases: sign bits of x and y are (0,1),(1,0),(0,0),(1,1).
 *                First case positive x is always > negative y, and negative x
 *                always !> positive y, thus (!signX & signY) handles these two
 *                cases. While (!signX | signY) handles last two cases it's
 *                both positive or both negative, in these cases, if x > y, or
 *                value is true, then x > y.
 */
int isGreater(int x, int y) {
  int value = !((x + ~y) >> 31);
  int signX = x >> 31;
  int signY = y >> 31;
  return ((!signX) & signY) | (value & ((!signX) | signY));
  //return 2;
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 *   Description: We get the sign bit and associate it with 0...01. If positive,
 *                then 0...0 & 0...01 will be 0 and 1...1 & 0...01 will be 1.
 */
int isNegative(int x) {
  return (x >> 31) & 0x1;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 *   Description: We start by multiplying 5, since 5 is 0...0101, thus it is
 *                (x << 2) + x, then if multFive is negative, we add 2^3 - 1 = 7
 *                before right shift. Then we divide by 8 and return.
 */
int multFiveEighths(int x) {
  int multFive = (x << 2) + x;
  int adjust = 7 & (multFive >> 31);
  return (multFive + adjust) >> 3;;
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 *   Description: We get the magnitude by adding 2^32 to x if x is negative, and
 *                adding nothing if x is positive. then we add 2 * (-mag) if x
 *                is negative and add nothing if x is positive. Thus producing
 *                two's complement representation.
 */
int sm2tc(int x) {
  int mag, tc;
  mag = ((1 << 31) & (x >> 31)) + x;
  tc = mag + (((~mag + 1) << 1) & (x >> 31));
  return tc;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 *   Description: 
 */
unsigned float_i2f(int x) {
  int e = 158;
  int mask = 1<<31;
  int sign = x&mask;
  int frac;
  if (x == mask)
      return mask | (158<<23);
  if (!x)
      return 0;
  if (sign)
      x = ~x + 1;
  while (!(x&mask)) {
      x = x<<1;
      e = e -1;
  }
  frac = (x&(~mask)) >> 8;
  if (x&0x80 && ((x&0x7F) > 0 || frac&1))
      frac = frac + 1;
  return sign + (e<<23) + frac;

  //return 2;
}
