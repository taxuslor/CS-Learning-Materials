- *Propose-and-Reject Algorithm(Gale-Shapley Algorithm):*

  Every Morning: Each job proposes (i.e. makes an offer) to the most preferred candidate on its list who has not yet rejected this job.

  Every Afternoon: Each candidate collects all the offers she received in the morning; to the job offer she likes best among these, she responds “maybe” (she now has it *in hand* or *on a string*), and to the other offers she says “no” (i.e., she rejects them). (This is just a way for us to virtually model that there are no “exploding offers” and a job can’t withdraw an offer once an offer is made.)

  Every Evening: Each rejected job crosses off the candidate who rejected its offer from its list.

  The above loop is repeated each successive day until there are no offers rejected. At that point, each candidate has a job offer in hand (i.e. on a string); and on this day, each candidate accepts their offered job (i.e. the job offer she has in hand) and the algorithm terminates.

- *Lemma 4.1. The propose-and-reject algorithm always halts.*

- A matching is unstable if there is a job a candidate who both prefer working with each other over their current matchings. We call such a pair a rouge couple. A mathcing of n jobs and n candidates is stable if it has no rouge couples.

- *Lemma 4.2 (Improvement Lemma). If job J makes an offer to candidate C on the kth day, then on every susbsequent day C has a job offer in hand (on a string) which she likes at least as much as J.*

- *Definition 4.1 (Well-ordering principle). If S ⊆ N and S ≠ ∅, then S has a smallest element.*

- *Lemma 4.3. The propose-and-reject algorithm always terminates with a matching.*

- *Theorem 4.1. The matching produced by the algorithm is always stable.*

- *Definition 4.2 (Optimal candidate for a job). For a given job J, the optimal candidate for J is the highest rank cnadiadate on J's Preference list that J could be paired with any stable matching.*

- *Definition 4.3 (Optimal job for a candidate). For a given candidate C, the optimal job for C is the highest-ranked job on C's preference list that C would be paired with in any stable matching.*

- *Theorem 4.2. The matching output by the Propose-and-Reject algorithm is job/employer optimal.*

- *Theorem 4.3. If a matching is employer/job optimal, then it is also candidate pessimal.*