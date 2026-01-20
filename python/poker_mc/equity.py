import poker_mc

def equity(hero, board=None, iterations=100_000):
    if board is None:
        board = []
    return poker_mc.estimate_equity(hero, board, iterations)
