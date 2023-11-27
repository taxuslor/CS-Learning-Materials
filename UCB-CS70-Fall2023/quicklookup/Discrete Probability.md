- Random experimen: In general, a random experiment consists of drawing a sample of *k* elements from a set *S* of cardinality *n*. The outcome of a random experiment is called a *sample point*, and the *sample space* (often denoted by Ω) is the set of all possible outcomes of the experiment.

- A probability space is a sample space Ω, together with a probability P[ω] (often also denoted as Pr[ω]) for each sample point ω, such that

  - (Non-negativity): 0 ≤ P[ω] ≤ 1 for all ω ∈ Ω.
  - (Total one): ∑(ω∈Ω) P[ω] = 1.

- Definition 14.1 (Conditional Probability). *For events A, B ⊆ Ω in the same probability space such that* P[*B*] > 0*, the conditional probability of A given B is* P[*A*|*B*]= P[A∩B]/P[B]

- Bayesian Inference: A way to update knowledge after making an observation.

  - For example, we may have an estimate of the probability of a given event *A*. After event *B* occurs, we can update this estimate to P[*A* | *B*]. In this interpretation, P[*A*] can be thought of as a *prior* probability: our assessment of the likelihood of an event of interest, *A*, *before* making an observation. It reflects our prior knowledge. P[*A* | *B*] can be interpreted as the *posterior* probability of *A* after the observation. It reflects our updated knowledge.

- Bayes’ Rule: P[*A*|*B*]= P[A∩B]/P[B] = P[B|A]\*P[A]

- Total Probability Rule: P[B]=P[A∩B]+P[¬A∩B]=P[B|A]P[A] + P[B|¬A]P[¬A]=P[B|A]P[A] + P[B|¬A]\*(1-P[A])

- Definition 14.2 (Partition of an event). *We say that an event A is partitioned into n events A*1,...,*An* if

  1. A* = *A*1 ∪*A*2 ∪···∪*A**n**, and*

  2. Ai ∩ *Aj* = ∅ *for all i* ≠ *j (i.e., A*1,...,*An* *are mutually exclusive).*

- Definition 14.3 (Independence). *Two events A*,*B in the same probability space are said to be independent if* P[*A*∩*B*] = P[*A*]×P[*B*]*.* P[A|B] = P[A]

- Definition 14.4 (Mutual independence). *Events A*1,...,*A**n* *are said to be mutually independent if for* *every* *subset I* ⊆ {1,...,*n*} *with size* |*I*| ≥ 2*,* P[∩*i*∈*I**A**i*] = ∏P[*Ai*].

- Definition 14.5 (Mutual independence). *Events A*1,...,*A**n* *are said to be mutually independent if for all* *Bi* ∈ {*Ai*,¬*Ai*},*i* = 1,...,*n,* P[*B*1 ∩···∩*Bn*] = ∏(i=1,n)P[*Bi*].

- Theorem 14.1 (Product Rule). *For any events A*, *B, we have* P[*A*∩*B*]=P[*A*]P[*B*|*A*].

- Theorem 14.2 (Inclusion-Exclusion). *Let A*1 , . . . , *A**n* *be events in some probability space, where n* ≥ 2*. Then, we have* P[*A*1 ∪···∪*An*] = ∑(k=1,n)(−1)^(*k*−1) ∑(S⊆{1,...,n}:|S| = k)P[∩(*i*∈*S*)*Ai*]

- Definition 15.1 (Random Variable). *A random variable X on a sample space* Ω *is a function X* : Ω → R *that assigns to each sample point* ω ∈ Ω *a real number X*(ω)*.*

- Definition 15.2 (Distribution). *The distribution of a discrete random variable X is the collection of values* {(*a*,P[*X* = *a*]) : *a* ∈ A }*, where* A *is the set of all possible values taken by X.*

- Bernoulli Distribution: *X* ∼ Bernoulli(*p*)  P[*X* =*i*]=
  									p, if i =1
  									1-p, if i =0

- Binomial Distribution: *X* ∼ Bin(*n*, *p*)  P[*X*=*i*]= (n,i)p^i(1−*p*)^(n-i) , for*i*=0,1,...,*n*.

- Hypergeometric Distribution: *Y* ∼ Hypergeometric(*N*,*B*,*n*)  P[Y=k] = (n,k)(N-B,n-k)/(N,n)

- Definition 15.3. *The joint distribution for two discrete random variables X and Y is the collection of values* {((*a*,*b*),P[*X*=*a*,*Y*=*b*]):*a*∈A,*b*∈B},where *A* is the set of all possible values taken by X and *B* is the set of all possible values taken by Y. 

- Marginal distribution: given a joint distribution for *X* and *Y* , the distribution P[*X* = *a*] for *X* is called the *marginal distribution* for *X*,  and can be found by “summing” over the values of *Y*.  P[*X* =*a*]= ∑(b∈B)P[*X* =*a*,*Y* =*b*].

- Definition 15.4 (Independence). *Random variables X and Y on the same probability space are said to be* independent *if the events X* = *a and Y* = *b are independent for all values a*, *b. Equivalently, the joint distribution of independent r.v.’s decomposes as* P[*X* =*a*,*Y* =*b*]=P[*X* =*a*]P[*Y* =*b*], ∀*a*,*b*.

- Definition 15.5 (Expectation). *The expectation of a discrete random variable X is defined as E[X*]= ∑(*a*∈A)*a*×P[*X*=*a*],  *where the sum is over all possible values taken by the r.v.*

- Theorem 15.1. *For any two random variables X and Y on the same probability space, we have* E[*X* +*Y*] = E[*X*]+E[*Y*]. *Also, for any constant c, we have* E[*cX*] = *c*E[*X*].

- Definition 16.1 (Variance). *For a r.v. X with expectation* E[*X*] = μ*, the* variance *of X is defined to be* Var(*X*) = E(*X* − μ)2. *The square root* σ(*X*) := √(Var(*X*)) *is called the* standard deviation *of X.*

- Theorem16.1. Forar.v.X with expectation *E[*X*] = μ*, we have *Var(*X*) = E*[X<sup>2</sup>]−μ<sup>2</sup>*.*

- Theorem 16.2. *For* independent *random variables X*,*Y, we have* E[*XY*] = E[*X*]E[*Y*]*.*

- Theorem 16.3. *For* independent *random variables X*,*Y, we have* Var(*X* +*Y*) = Var(*X*)+Var(*Y*).

- Definition 16.2 (Covariance). *The* covariance *of random variables X and Y , denoted* Cov(*X* , *Y* )*, is defined as* Cov(*X* , *Y* ) = E[(*X* − μ*X* )(*Y* − μ*Y* )] = E[*X Y* ] − E[*X* ] E[*Y* ], *where* μ*X* = E[*X*] *and* μ*Y* = E[*Y*]*.*

- Definition 16.3 (Correlation). *Suppose X and Y are random variables with* σ (*X* ) > 0 *and* σ (*Y* ) > 0*. Then, the correlation of X and Y is defined as* Corr(*X*,*Y*)= Cov(*X*,*Y*)/σ(*X*)σ(*Y*)

- Theorem 16.4. *For any pair of random variables X and Y with* σ(*X*) > 0 *and* σ(*Y*) > 0*,* −1 ≤ Corr(*X*,*Y*) ≤ +1.

- Theorem 17.1 (Markov’s Inequality). *For a* nonnegative *random variable X (i.e., X*(ω) ≥ 0 *for all* ω ∈ Ω*) with finite mean,* P[X≥c] ≤ E[X]/c *for any positive constant c.*

- Theorem 17.2 (Generalized Markov’s Inequality). *Let Y be an arbitrary random variable with finite mean. Then, for any positive constants c and r,* P[|*Y*|≥*c*] ≤ E[|*Y*|<sup>*r*</sup>] /*c* <sup>*r*</sup>

- Theorem 17.3 (Chebyshev’s Inequality). *For a random variable X with finite expectation* E[*X*] = μ*,* P[|*X*−μ|≥*c*]≤ Var(*X*)/c<sup>2</sup>, *and for any positive constant c.*

- Theorem17.4(Law of Large Numbers). *Let X*1, *X*2,...,*be a sequence of i. i.d.(independent and identically distributed) random variables with common finite expectation* E[*Xi*] = μ *for all i. Then, their partial sums Sn* = *X*1 +*X*2 +···+*Xn* *satisfy* P[/*n**S**n*−μ <ε] →1 *as n*→ ∞, *for every* ε > 0*, however small.*

- Definition 19.1 (Geometric Distribution). *A random variable X for which* P[*X* =*i*]=(1−*p*)<sup>*i*−1</sup>*p*, *for i*=1,2,3,..., *is said to have the geometric distribution with parameter p. This is abbreviated as X* ∼ Geometric(*p*)*.*

- Theorem 19.1 (Tail Sum Formula). *Let X be a random variable that takes values in* {0,1,2,...}*. Then* E[*X*] = ∑(i=1,∞) P[*X* ≥ *i*].

- Theorem 19.2. *For X* ∼ Geometric( *p*)*, we have* E[*X* ] = 1 / *p* *.*

- Theorem 19.3. *For X* ∼ Geometric( *p*)*, we have* Var (*X*) = 1− *p* / p<sup>2</sup>*.*

- Definition 19.2 (Poisson distribution). *A random variable X for which* P[*X*=*i*]= λ*i* / *i*! \* *e*<sup>−λ</sup> , *for i*=0,1,2,...  *is said to have the Poisson distribution with parameter* λ *. This is abbreviated as X* ∼ Poisson(λ )*.*

- Theorem 19.4. *For a Poisson random variable X* ∼ Poisson(λ )*, we have* E[*X* ] = λ *and* Var (*X* ) = λ *.*

- Theorem 19.5. *Let X* ∼ Poisson(λ ) *and Y* ∼ Poisson(μ ) *be independent Poisson random variables. Then, X* +*Y* ∼ Poisson(λ + μ)*.*

- Theorem 19.6. *Let X* ∼ Binomial(*n*, λ/*n* ) *where* λ > 0 *is a fixed constant. Then for every i* = 0,1,2,...*,* P[*X* = *i*] → λ*i* / *i*! \* *e*<sup>−λ</sup> as n → ∞.

- Definition 20.1. *The joint distribution for two discrete random variables X and Y is the collection of values* {((*a*,*b*),P[*X*=*a*,*Y*=*b*]):*a*∈A,*b*∈B}*,where* A is the set of all possible values taken by X and *B* is the set of all possible values taken by Y .

- *The law of iterated expectations:* E[*X*]=E[E[*X* |*Y*]]= ∑(y∈B)E[*X* |*Y* =*y*]P[*Y* =*y*].

- Definition 21.1 (Probability Density Function). *A* probability density function *(p.d.f.) for a real-valued random variable X is a function f* : R → R *satisfying:*

  1. f is non-negative: f(*x*) ≥ 0 *for all x* ∈ R*.*
  2. The total integral of f is equal to 1: ∫(-∞,∞)f(x)dx = 1.
     *Then the distribution of X is given by:*

  P[*a*≤*X* ≤*b*]=∫(a,b)f(x)dx for all a < b.

- Definition 21.2 (Expectation). *The expectation of a continuous r.v. X with probability density function f is* E[*X*]= ∫(-∞,∞) *xf*(*x*)*dx*. 

- Definition 21.3 (Variance). *The variance of a continuous r.v. X with probability density function f is* Var(*X*)=E [(*X*−E[*X*])<sup>2</sup>] =E [*X*<sup>2</sup>] −E[*X*]<sup>2</sup> =∫(-∞,∞)*x<sup>2</sup> f*(*x*)*dx* − (∫(-∞,∞)*xf*(*x*)*dx*)<sup>2</sup> .

- Definition 21.4 (Joint Density). *A* joint density function *for two random variable X and Y is a function f* : R<sup>2</sup> → R *satisfying:*

  1. f is non-negative: f*(*x*,y*) ≥ 0 *for all x*,*y* ∈ R.

  2. The total integral of f is equal to*1*:∬ *f*(*x*,*y*)*dxdy*=1*.*

  *Then the joint distribution of X and Y is given by:*
  P[*a*≤*X* ≤*b*, *c*≤*Y* ≤*d*]=∬f(x,y)dxdy for all *a*≤b and *c*≤d

- Theorem 21.1. *The joint density of independent r.v.’s X and Y is the product of the marginal densities:*

  *f*(*x*,*y*)= *f*<sub>*X*</sub>(*x*)*f*<sub>*Y*</sub>(*y*) *for all x*,*y*∈R.

- Definition 21.7 (Normal Distribution). *For any* μ ∈ R *and* σ > 0*, a continuous random variable X with p.d.f.* *f*(*x*) = 1/√2πσ<sup>2</sup> \* *e*<sup>−(*x*−μ)<sup>2</sup>/(2σ)<sup>2</sup></sup> *is called a normal random variable with parameters* μ *and* σ<sup>2</sup>*, and we write X* ∼ *N*(μ,σ<sup>2</sup>)*. In the special case* μ = 0 *and* σ = 1*, X is said to have the standard normal distribution.*

- Theorem 21.5 (Central Limit Theorem). *Let X*1,*X*2,... *be a sequence of i.i.d. random variables with common finite expectation* E[*X* *i*] = μ *and finite variance* Var(*X* *i*) = σ<sup>2</sup>*. Let S* *n* = ∑(*n*,*i*=1) *X**i**. Then, the distribution* *of* *Sn*−*n*μ / √σ*n* *converges to N*(0,1) *as n* → ∞*. In other words, for any constant c* ∈ R*,* P [*Sn*−*n*μ / √σ*n*≤*c*] → 1 / √2𝝅 ∫*e<sup> -x<sup>2</sup>/2</sup>dx* as *n* → ∞.

  

  

  

  

  

  

  