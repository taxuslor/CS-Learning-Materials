- *Mathematical Induction:* 
  	Simple Induction:

  ​	Base Case: Prove that P(0) is true.

  ​	Induction Hypothesis: For arbitrary k ≥ 0, assume that P(k) is true.

  ​	Inductive Step: With the assumption of the Induction Hypothesis in hand, show that 	P(k + 1) is true.
  ​	Strong Induction:
  ​	Base Case: Prove that P(0) is true.
  ​	Induction Hypothesis: For arbitrary k ≥ 0, assume that ∧(i=0,k)P(i) is true.

  ​	Inductive Step: With the assumption of the Induction Hypothesis in hand, show that 	P(k + 1) is true.

- *Theorem 3.1. ∀ n ∈ N, ∑(i=0,n) i = n(n+1)/2.*

- *Theorem 3.2. For all n ∈ N, n^3 - n is divisible by 3.*

- *Theorem 3.3. Let P(n) denote the statement "Any map of a rectangle which is divided into regions by drawing straight lines with n lines is two-colorable". Then, it holds that ∀ n ∈ N P(n).*

- *Theorem 3.4. For all n>=1, the sum of the first n odd numbers is n^2.*

- *Theorem 3.5. For all n>=1, ∑(i=1,n) 1/(i^2) <= 2 - 1/n.*

- *Theorem 3.6. For every natural number n>=12, it holds that n = 4x+5y for some x,y ∈ N.*

- *Fibonacci’s rabbits:*

  - *F*(0)=0.

  - *F*(1)=1.

  - For *n* ≥ 2, *F*(*n*) = *F*(*n*−1)+*F*(*n*−2).

  - Recursive Algorithm:

    function F(n):

    ​	if n = 0 then return 0
    ​	if n = 1 then return 1
    ​	else return F(n-1) + F(n-2)

  - Iterative Algorithm:
    function F2(n):

    ​	if n = 0 then return 0
    ​	if n = 1 then return 1
    ​	a = 1
    ​	b = 0
    ​	for k = 2 to n do
    ​		temp = a
    ​		a = a + b

    ​		b = temp
    ​	return a

- *Binary Search:*
  // precondition: W is a word and D is a subset of the dictionary with at least 1 page.

  // postcondition: Either the definition of W is returned, or "W not found" is returned.

  findWord(W, D) {

  // Base case

  if (D has precisely one page)

  ​	Look for W in D by brute force.

  ​	If found, return its definition; else, return "W not found".

​	 // Recursive case

​	Let W’ be the first word on the middle page of D.

​	 if (W comes before W’)

​		 return findWord(first half of D)

​	 else

​		return findWord(second half of D)

​	}

- *Bernoulli's Inequality: (1+x)^n >= 1+nx if n is a natural number and 1+x>0.* 

- *Theorem: For all n ∈ N, n>1 ⇒ n!<n^n*