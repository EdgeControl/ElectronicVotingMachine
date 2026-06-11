# 🗳️ EVM — Electronic Voting Machine (Single Ballot, 2-Posting)

An Arduino Mega-based Electronic Voting Machine supporting up to **15 candidates** across **2 ballot postings**, with EEPROM vote persistence, password-protected admin access, and LCD display output.

---

## 📋 Features

- Supports up to **15 candidates** across 2 physical posting panels (Candidates 1–8 on Panel 1, 9–15 on Panel 2)
- **EEPROM-backed vote storage** — votes survive power cycles
- **Password-protected admin and delete menus** using candidate buttons as input
- **LED feedback** per candidate button press
- **Buzzer confirmation** on successful vote registration
- **Red/Green LED status indicators** (Red = locked, Green = unlocked/allowed)
- **16×2 I2C LCD** display for all UI interactions
- **Paginated result viewing** — navigate through 4 pages of vote counts
- **Result viewing mode** — accessible without admin access
- **Serial monitor output** for debugging and audit logging

---

## 🔧 Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino Mega 2560 | 1 |
| 16×2 I2C LCD (address `0x27`) | 1 |
| Tactile push buttons | 20 |
| LEDs (candidate indicators) | 15 |
| Red LED | 1 |
| Green LED | 1 |
| Buzzer (active) | 1 |
| Resistors (220Ω for LEDs) | as needed |
| Breadboard / PCB | — |

---

## 📌 Pin Mapping

### Candidate Buttons (INPUT_PULLUP)

| Candidate | Pin |
|---|---|
| C1 | 22 |
| C2 | 23 |
| C3 | 24 |
| C4 | 25 |
| C5 | 26 |
| C6 | 27 |
| C7 | 28 |
| C8 | 29 |
| C9 | 30 |
| C10 | 31 |
| C11 | 32 |
| C12 | 33 |
| C13 | 34 |
| C14 | 35 |
| C15 | 36 |

### Candidate LEDs (OUTPUT)

| Candidate | Pin |
|---|---|
| C1 | 37 |
| C2 | 38 |
| ... | ... |
| C15 | 51 |

### Control Pins

| Function | Pin | Mode |
|---|---|---|
| Admin unlock | 7 | INPUT_PULLUP |
| Delete trigger | 53 | INPUT_PULLUP |
| Result view | 52 | INPUT_PULLUP |
| Forward (navigate) | 6 | INPUT_PULLUP |
| Backward (navigate) | 5 | INPUT_PULLUP |
| Red LED | 3 | OUTPUT |
| Green LED | 2 | OUTPUT |
| Buzzer | 4 | OUTPUT |

---

## 📦 Dependencies

Install the following libraries via the Arduino Library Manager:

- [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C) — for I2C LCD
- `Wire` — built-in Arduino library
- `EEPROM` — built-in Arduino library

---

## 🚀 Getting Started

1. **Clone this repository**
   ```bash
   git clone https://github.com/your-username/evm-single-ballot.git
   ```

2. **Open in Arduino IDE**
   Open the `.ino` file in Arduino IDE 1.8+ or Arduino IDE 2.x.

3. **Install libraries**
   Go to `Sketch → Include Library → Manage Libraries` and install `LiquidCrystal_I2C`.

4. **Upload to Arduino Mega**
   Select `Tools → Board → Arduino Mega 2560` and upload.

5. **(Optional) Clear EEPROM on first use**
   Uncomment the EEPROM clear block in `setup()` for a fresh start:
   ```cpp
   for(int a = 0; a <= 20; a++) {
     EEPROM.write(a, 0);
   }
   ```
   Re-comment and re-upload after clearing.

---

## 🔐 Default Admin Password

The password is entered using **candidate buttons** as a numeric keypad.

```
Default: [1] → [4] → [15]
(Press Candidate 1, then Candidate 4, then Candidate 15)
```

To change it, modify this line in the source:
```cpp
const int password[] = {1, 4, 15};
```

---

## 🗺️ How It Works

### Voting Flow

```
Power ON
  └─> Main Menu (Red LED on)
        ├─> Admin PIN pressed → Enter password
        │     └─> Correct → Admin Vote Mode (Green LED on)
        │           └─> Press candidate button → Vote registered → Machine locks
        ├─> Result PIN pressed → View vote counts (4 pages, navigate with Forward/Backward)
        └─> Delete PIN pressed → Enter password → EEPROM wiped
```

### 2-Posting (Dual Panel) Logic

- **Panel 1 (switching = true):** Candidates 1–8 are active
- **Panel 2 (switching = false):** Candidates 9–15 are active
- The machine alternates panels after each registered vote automatically

### EEPROM Address Map

| Candidate | EEPROM Start Address |
|---|---|
| C1 | 1 |
| C2 | 11 |
| C3 | 21 |
| C4 | 31 |
| C5 | 41 |
| C6 | 51 |
| C7 | 61 |
| C8 | 71 |
| C9 | 81 |
| C10 | 91 |
| C11 | 101 |
| C12 | 111 |
| C13 | 121 |
| C14 | 131 |
| C15 | 141 |

Each vote count is stored as an `int` (2 bytes), with 10-byte spacing between candidates.

---

## 📊 Viewing Results

1. Press the **Result button** (Pin 52) from the Main Menu.
2. Use **Forward** (Pin 6) / **Backward** (Pin 5) to navigate through 4 pages:
   - Page 1: C1–C4
   - Page 2: C5–C8
   - Page 3: C9–C12
   - Page 4: C13–C15
3. Press **Forward + Backward simultaneously** to exit.

---

## 🗑️ Deleting All Votes

1. Press the **Delete button** (Pin 53).
2. Enter the password using candidate buttons.
3. On correct password, all EEPROM addresses (0–160) are cleared to `0`.

> ⚠️ **Warning:** This action is irreversible. All vote data will be permanently erased.

---

## 🛠️ Serial Monitor

Connect at **9600 baud** to view:
- Boot messages
- Each vote registration event
- Password input feedback (`*`)
- Menu navigation states

---

## 📁 File Structure

```
evm-single-ballot/
├── evm_single_ballot.ino   # Main Arduino sketch
└── README.md               # This file
```

---

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you'd like to change.

---

## 📄 License

Copyright 2024 EdgeControl

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

> http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

### What this means for you

| | Allowed |
|---|---|
| ✅ Use commercially | Yes |
| ✅ Modify the code | Yes |
| ✅ Distribute copies | Yes |
| ✅ Private use | Yes |
| ✅ Patent use | Yes |
| ⚠️ Must include license & copyright notice | Required |
| ⚠️ Must state changes made | Required |
| ❌ Trademark use | Not granted |
| ❌ Liability / Warranty | Not provided |

---

*Built by **EdgeControl***
