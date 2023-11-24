- *Modular Arithmetic: If x (mod m) ≡ r, then x = mq + r where 0 ≤ r ≤ m − 1 and q is an integer.*

- *Generally, while carrying out any sequence of additions, subtractions or multiplications mod m, we get the same answer if we reduce any intermediate results mod m.*
- For any integer *m*, we say that *x* and *y* are *congruent modulo m* if they differ by a multiple of *m* or, in symbols, *x*≡*y* (mod*m*) ⇐⇒ *m*divides(*x*−*y*).
- In general, if we work modulo *m*, then we get *m* disjoint sets whose union is the set of all integers: these are often called *residue classes mod m*.
- *Theorem 6.1. If a ≡ c (mod m) and b ≡ d (mod m), then a + b ≡ c +d (mod m), and a \* b ≡ c \* d (mod m).*
- A bijection is a function for which every b ∈ B has a unique pre-image a ∈ A such that f (a) = b. Note that this consists of two conditions:
  1. f is onto: every b∈B has a pre-image a∈A.
  2. f is one-to-one: for all a,a′ ∈ A, if f(a) = f(a′) then a = a′.

- *Lemma: For a finite set A, f: A → A is a bijection if there is an inverse function g: A → A such that ∀x∈A g(f(x)) = x.*
- *Theorem 6.2. Let m,x be positive integers such that gcd(m,x) = 1. Then x has a multiplicative inverse modulo m, and it is unique (modulo m).*
- *Theorem 6.3. Let x>=y>0. Then gcd(x,y) = gcd(y,x (mod y)).*
- *Theorem 6.4. The algorithm above correctly computes the gcd of x and y.*
- *Fundamental Thoerem of Arithmetic: Every positive integer n>1 can be expressed uniquely in the form p1p2...pk, where each pi is a(not necessarily unique) prime number, up to reordering of the prime factors.*
- Chinese Remainder Theorem: For *m*,*n* with *gcd*(*m*,*n*) = 1 that there is exactly one *x* (mod *mn*) that satisfies the equations: *x*≡*a* (mod *n*)and *x*≡*b* (mod *m*).
- 