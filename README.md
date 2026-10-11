# LeetCode Journey

Daily LeetCode practice — problems solved, committed here to keep the grind visible and consistent.

## What this repo is

A personal archive of LeetCode solutions, synced automatically from my daily practice. Each problem lives in its own folder (`<id>-<problem-name>/`) containing:

- The solution file (`<id>-<Problem-Title>.cpp` / `.js`)
- A per-problem `README.md` with the problem statement, difficulty, and link back to LeetCode

Solutions are predominantly **C++**, with a couple of JavaScript solutions for the JavaScript-focused problem set (e.g. `2620-counter`, `2667-create-hello-world-function`). Alongside the daily grind there are topic-wise folders (`Array`, `DigitDP`, `Segment Tree`, `recursion`), daily-challenge batches (`DCP-09-26`, `DCP-10-26`), and a `Bug Bounty` folder with practice notes on labs and vulnerabilities.

## Tech stack

- **C++** (primary — the vast majority of solutions)
- **JavaScript** (a few LeetCode JS-track problems)
- **LeetPush** — a browser extension that auto-pushes each accepted LeetCode solution into this repo

## Project structure

```
.
├── 1-two-sum/                      # LeetPush folder: <id>-<slug>/
│   ├── 1-Two-Sum.cpp               #   solution
│   └── README.md                   #   problem statement + difficulty + link
├── 1011-capacity-to-ship-packages-within-d-days/
│   └── ...
├── DCP-09-26/, DCP-10-26/          # daily-challenge solution batches
├── Array/, DigitDP/, Segment Tree/, recursion/   # topic-wise practice
├── Bug Bounty/                     # bug-bounty practice notes (Labs, Vulneribility)
├── .vscode/                        # editor config
└── *.cpp (root)                    # older loose solution files
```

## Run it locally

This is a practice archive, not an app — there is no build system or package.json. To try a solution, compile any file with `g++`, for example:

```bash
g++ 1-two-sum/1-Two-Sum.cpp -o two-sum && ./two-sum
```

## Notes

- This repo is auto-synced by the **LeetPush** browser extension, so new commits appear here right after a solution is accepted on LeetCode. A README-only edit here is safe — it won't affect the sync.
- New challenges are welcome — if you have an interesting problem, reach out.

## Links

- LeetCode: https://leetcode.com/u/bhavesh1899287/
- Portfolio: https://bhavesh-portfolio189.vercel.app/
