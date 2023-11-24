- *We say that a is a root of the polynomial p(x) if p(a) = 0.* 

- *Property 1: A non-zero polynomial of degree d has at most d roots.*
- *Property 2: Given d+1 pairs (x1,y1),...,(xd+1,yd+1), with all the xi distinct, there is a unique polynomial p(x) of degree (at most) d such that p(xi) = yi for 1<=i<=d+1.*

- *Largrange interpolation: Denote by Δi(x) the degree d polynomial that goes through d+1points. Then Δi(x)= (∏(j≠i)(x −xj))/(∏(j≠i)(xi −xj)). Given d+1 pairs(x1,y1),...(xd+1,yd+1), we first construct the d+1 polynomials Δ1(x),...,Δd+1(x). p(x) = ∑(i=1,d+1)yiΔi(x).*