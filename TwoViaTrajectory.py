from sympy import *



def generateEquation(initialPos, finalPos, Finaltime):
    t, T = symbols('t T')
    a0, a1, a2, a3, a4, a5 = symbols('a0 a1 a2 a3 a4 a5')

    s = a0 + a1 * t + a2 * t ** 2 + a3 * t ** 3 + a4 * t ** 4 + a5 * t ** 5
    sdot = diff(s, t)
    sdotdot = diff(sdot, t)

    s0 = initialPos  # Position at t = 0
    sT = finalPos  # Position at t = T
    sdot0 = 0  # Velocity at t = 0
    sdotT = 0  # Velocity at t = T
    sdotdot0 = 0  # Acceleration at t = 0
    sdotdotT = 0  # Acceleration at t = T

    equation1 = Eq(s.subs(t, 0), s0)
    equation2 = Eq(s.subs(t, T), sT)
    equation3 = Eq(sdot.subs(t, 0), sdot0)
    equation4 = Eq(sdot.subs(t, T), sdotT)
    equation5 = Eq(sdotdot.subs(t, 0), sdotdot0)
    equation6 = Eq(sdotdot.subs(t, T), sdotdotT)

    solution = solve((equation1, equation2, equation3, equation4, equation5, equation6), (a0, a1, a2, a3, a4, a5))

    print(solution)
    s = s.subs(solution)
    s = s.subs(T, Finaltime)
    print(s)

T = symbols('T')
#generateEquation(10, 15, 20)
#¨s(0) = ¨s(T) = 0
print("X Axis:")
generateEquation(10, 20, 5)

print("Y Axis:")
generateEquation(0, 0, 20)

print("Z Axis:")
generateEquation(0, 0, 20)

