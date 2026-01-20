from poker_mc import equity, ev_call

hero = [51,50]       # As Ac
board = [12,25,38]   # example flop

eq = equity(hero, board, iterations=200_000)
ev = ev_call(eq, pot=100, call=40)

print("Equity:", eq)
print("EV:", ev)
