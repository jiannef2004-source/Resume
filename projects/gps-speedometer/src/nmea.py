"""Minimal NMEA parsing utilities for the GPS speedometer."""

from dataclasses import dataclass

KNOT_TO_MPH = 1.150779448
KNOT_TO_KMH = 1.852

@dataclass(frozen=True)
class SpeedFix:
    valid: bool
    knots: float

    @property
    def mph(self) -> float:
        return self.knots * KNOT_TO_MPH

    @property
    def kmh(self) -> float:
        return self.knots * KNOT_TO_KMH


def parse_rmc(sentence: str) -> SpeedFix:
    sentence = sentence.strip()
    if not (sentence.startswith("$GPRMC") or sentence.startswith("$GNRMC")):
        raise ValueError("Not an RMC sentence")
    fields = sentence.split(",")
    if len(fields) < 8:
        raise ValueError("Incomplete RMC sentence")
    valid = fields[2] == "A"
    try:
        knots = float(fields[7] or 0.0)
    except ValueError as exc:
        raise ValueError("Invalid speed field") from exc
    return SpeedFix(valid=valid, knots=knots)
