- *Sampling without replacement: We pick k ≤ n elements from an n-element set S = {1, 2, . . . , n} one at a time while removing the sampled element from S.*

- First Rule of Counting: If an object can be made by a succession of *k* choices, where there are *n*1 ways of making the first choice, and *for every* way of making the first choice there are *n*2 ways of making the second choice, and *for every* way of making the first and second choice there are *n*3 ways of making the third choice, and so on up to the *nk*-th choice, then the total number of distinct objects that can be made in this way is the product *n*1 ×*n*2 ×*n*3 ×···×*nk*.

- Second Rule of Counting: Assume an object is made by a succession of choices, and the order in which the choices are made does not matter. Let *A* be the set of ordered objects and let *B* be the set of unordered objects. If there exists an *m*-to-1 function *f* from *A* to *B*, we can count the number of ordered objects (pretending that the order matters) and divide by *m* (the number of ordered objects per unordered objects) to obtain |*B*|, the number of unordered objects.
- Sampling with replacement: We wish to consider a different scenario of sampling where after we choose an element from *S* = {1,2,...,*n*}, we throw it back into *S* so that we can choose it again.
- Zeroth Rule of Counting: If a set *A* can be placed into a one-to-one correspondence with a set *B* (i.e. you can find a bijection between the two — an invertible pair of maps that map elements of *A* to elements of *B* and vice-versa), then |*A*| = |*B*|.

- *Theorem 10.1 (Binomial Theorem). For all n ∈ N, (a+b)^n = ∑(k=0,n) (n k) a^k \* b^(n-k).*
- *Corollary 10.1. For all n ∈ N, ∑(k=0,n) (n k) (-1)^k = 0.*

- *Hockey-stick identity: (n k+1) = (n-1 k) + (n-2 k) + ... + (k k).*

- *Fixed points: If πi = i, we say i is a  fiexed point of the permutation of πi.*
- *Derangement: A permutation with no fixed points is called a derangement.*
- Theorem 10.2. *For an arbitrary positive integer n* ≥ 3*, the number D**n* *of derangements of* {1, . . . , *n*} *satisfies Dn* = (*n* − 1)(*Dn*−1 + *Dn*−2). 

- *Inclusive-exclusive Principle: |A∪B∪C|=|A|+|B|+|C|-|A∩B|-|A∩C|-|B∩C|+|A∩B∩C|*

