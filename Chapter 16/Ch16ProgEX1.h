/* Start developing a header file of preprocessor definitions
 * that you want to use.
 */
#define DBUG

#define SQRT(X) _Generic(X,\
		long double : sqrtl,\
		float       : sqrtf,\
		default     : sqrt)(X)

#define FLUSH while (getchar() != '\n') continue

#define CHECKCHAR _Static_assert(CHAR_BIT == 8, "Bits in a CHAR is not equal to 8")

#define CHECKSTD11 _Static_assert(__STDC_VERSION__ != 201112L, "Not using C11 ANSI standard")
