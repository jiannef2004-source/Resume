# GPS Speedometer

A lightweight Python speedometer for Raspberry Pi that reads standard NMEA GPS data and displays vehicle speed in mph or km/h. The project can also run in demo mode using bundled sample NMEA sentences, so the interface can be tested without GPS hardware.

## Features

- Parses `$GPRMC` / `$GNRMC` NMEA sentences.
- Converts knots to mph and km/h.
- Rejects invalid GPS fixes.
- Terminal display for Raspberry Pi or laptop use.
- Unit tests for parsing and speed conversion.

## Hardware

- Raspberry Pi (or any computer running Python 3.10+)
- USB GPS receiver that outputs NMEA data

## AI-assisted development

If Claude Code or GitHub Copilot is used to extend this project, meaningful changes should be recorded in `AI_DEVELOPMENT_LOG.md`. Only actual tool usage should be documented.
