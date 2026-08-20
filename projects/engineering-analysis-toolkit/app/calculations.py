"""Pure calculation functions used by the engineering toolkit."""


def dc_power(voltage_v: float, current_a: float) -> float:
    return voltage_v * current_a


def resistance_from_vi(voltage_v: float, current_a: float) -> float:
    if current_a == 0:
        raise ValueError("Current must be non-zero")
    return voltage_v / current_a


def scale_4_20ma(current_ma: float, low: float, high: float) -> float:
    if not 4.0 <= current_ma <= 20.0:
        raise ValueError("Current must be between 4 and 20 mA")
    return low + ((current_ma - 4.0) / 16.0) * (high - low)


def rc_time_constant(resistance_ohm: float, capacitance_f: float) -> float:
    if resistance_ohm < 0 or capacitance_f < 0:
        raise ValueError("R and C must be non-negative")
    return resistance_ohm * capacitance_f


def voltage_divider(vin: float, r1: float, r2: float) -> float:
    if r1 < 0 or r2 <= 0:
        raise ValueError("R1 must be non-negative and R2 must be positive")
    return vin * r2 / (r1 + r2)
