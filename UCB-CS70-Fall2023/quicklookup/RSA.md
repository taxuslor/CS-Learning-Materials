- The RSA scheme is based heavily on modular arithmetic. Let *p* and *q* be two large primes (typically having, say, 512 bits each), and let *N* = *pq*. We will think of messages to Bob as numbers modulo *N*, excluding the trivial values 0 and 1. (Larger messages can always be broken into smaller pieces and sent separately.)

  Also, let *e* be any number that is relatively prime to ( *p* − 1)(*q* − 1). (Typically *e* is chosen to be a small value such as 3.) Then Bob’s *public key* is the pair of numbers (*N*,*e*). This pair is published to the whole world. (Note, however, that the numbers *p* and *q* are *not* public; this point is crucial and we will return to it below.)

  What is Bob’s private key? This will be the number *d*, which is the *inverse* of *e* mod (*p* − 1)(*q* − 1). (This inverse is guaranteed to exist because *e* and ( *p* − 1)(*q* − 1) are coprime.)

  We are now in a position to describe the encryption and decryption functions:
  [Encryption] When Alice wants to send a message *x* (assumed to be an integer mod *N*) to Bob, she computes the value *E*(*x*)≡*x*^*e* (mod*N*) and sends this to Bob.
  [Decryption] Upon receiving the value *y* = *E*(*x*), Bob computes *D*(*y*) ≡ *y*^*d* (mod *N*); this will be equal to the original message *x*.

- *Theorm 7.1. Under the above definitions of the encryption and decryption functions E and D, we have D(E(x)) ≡ x (mod N) for every possible message x ∈ {0,1,...,N −1}.*

- *Theorem 7.2 (Fermat's Little Theorem). For any prime p and any a ∈ {1,2,...,p-1}, we have a^(p-1)≡1 (mod p).*

- *Theorem 7.3 (Prime Number Theorem).Let π(n) denote the number of primes that are less than or equal to n. Then for all n ≥ 17, we have π(n)≥ n/ln(n) . (And in fact,lim(n→∞) π(n)/(n/ln(x)) = 1.)*

