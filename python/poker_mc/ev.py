def ev_call(equity, pot, call):
    return equity*pot - (1-equity)*call
