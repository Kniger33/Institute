power_set([], []).
power_set([H | T1], [H | T2]) :- power_set(T1, T2).
power_set([_ | T1], T2) :- power_set(T1, T2).

c([], 0, []).
c([H | T1], N, [H | T2]) :- N > 0, N1 is N - 1, c(T1, N1, T2).
c([_ | T1], N, T2) :- c(T1, N, T2).
