# expose extension symbols under the package name
from ._poker_mc import estimate_equity
from .equity import equity
from .ev import ev_call  # adjust if ev_call lives elsewhere

__all__ = ["equity", "ev_call"]
