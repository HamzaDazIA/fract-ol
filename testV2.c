#include <stdio.h>

typedef struct d_complex
{
    double  real;

    double  i;
}       t_complex;

int main()
{
    t_complex   z;
    t_complex   c;
    double  tmp_z;


    c.i = 1.5;
    c.real = -0.5;

    int i = 0;

    while (i < 52) {
    tmp_z = (z.real * z.real) - (z.i * z.i); // Real part of z²
    z.i = 2 * z.real * z.i;                  // Imaginary part of z²
    z.real = tmp_z;                           // Update z to z²

    z.real += c.real; // Add c's real part: z = z² + c
    z.i += c.i;       // Add c's imaginary part

    printf("Iteration %d: z = %f + %fi\n", i, z.real, z.i);
    i++;
}
    return 0;

}