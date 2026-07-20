# Lecture: Practical SAT Solving

_Summer Term 2026 • [GitHub repository](https://github.com/satlecture/kit2026) • [Web page](https://satlecture.github.io/kit2026/) • Karlsruhe Institute of Technology (KIT)_

This lecture with exercises is offered by [Ashlin Iser (ITI Sanders)](https://ae.iti.kit.edu/english/3986.php) and [Dominik Schreiber (KASTEL-VADS SAtRes)](https://satres.kit.edu/schreiber), with [Niccolò Rigi-Luperti (SAtRes)](https://satres.kit.edu/team/) serving as co-manager of exercises.

The lecture provides a friendly and practical overview of propositional satisfiability (SAT) solving, covering its theoretical background, important algorithms and techniques, parallelization, proofs, applications, and related tools (MaxSAT, SMT). No particular prior knowledge beyond basic foundations of computer science is required.

All lectures and exercises take place at **15:45 in building 50.34 room 301**.
Our first appointment is the lecture on **Monday, April 20**.

## Lectures

We try to link each slide set here shortly before the lecture takes place.
See also [the page from last year](https://github.com/satlecture/kit2025).

(to be extended)

* **Monday, April 20**: [L1 - Organisation, Introduction, Applications, Encodings, IPASIR](slides/l01-introduction.pdf) _[AI+DS]_
* **Monday, April 27**: [L2 - Tractable Subclasses, Encodings](slides/l02-encodings.pdf) _[AI]_
* **Monday, May 4**: [L3 - Elementary SAT Solving Algorithms (SLS, Resolution, Saturation, DP, DPLL)](slides/l03-sls-dpll.pdf) _[DS]_
* **Monday, May 11**: [L4 - Application Highlights I (until slide 13)](slides/l04-application-highlights-1.pdf) _[DS]_
* **Monday, May 18**: [L5 - Application Highlights II (from slide 14)](slides/l04-application-highlights-1.pdf) _[DS]_
* **Monday, June 1**: [L6 - Elementary SAT Solving Heuristics, Conflict-Driven Clause Learning](slides/l06-heuristics-cdcl.pdf) _[AI]_
* **Monday, June 8**: [L7 - Conflict-Driven Clause Learning](slides/l07-cdcl.pdf) _[AI]_
* **Monday, June 15**: [L8 - Preprocessing](slides/l08-preprocessing.pdf) _[AI]_
* **Monday, June 22**: [L9 - Redundancy Notions and Proof Systems](slides/l09-redundancy-proofs.pdf) _[AI]_
* **Monday, June 29** and **Monday, July 6**: [L10 - Parallel SAT Solving](slides/l10-parallel.pdf) _[DS]_
* **Monday, July 13**: [L11 - Proof Pragmatics and Parallel Proof Tech](slides/l11-proof-pragmatics-parallel.pdf) _[DS]_
* **Monday, July 20**: **(remote lecture - contact us for link)** [L12 - Satisfiability Modulo Theories](slides/l12-smt.pdf) _[DS]_

## Exercises

* **Tuesday, May 5**: E1 - Getting Started, [Release of Exercise Sheet 1 (Introduction, Encodings)](exercises/ex1.pdf) _[AI]_
* **Tuesday, May 19**: E2 - Discussing Exercise Sheet 1 (Introduction, Encodings), [Release of Exercise Sheet 2 (Applications, Local search)](exercises/ex2.pdf) _[DS]_
* **Tuesday, June 2**: E3 - Discussing Exercise Sheet 2 (Applications) and 1 (Graph Coloring competition), [Release of Exercise Sheet 3 (Resolution, CDCL, SDVSTP)](exercises/ex3.pdf) _[AI]_
* **Tuesday, June 16**: E4 - Discussing Exercise Sheet 3 (CDCL, MC-DPLL) and 2 (Local Search competition), [Release of Exercise Sheet 4 (Preprocessing, SDVSTPP)](exercises/ex4.pdf) _[NRL]_
* **Tuesday, June 30**: E5 - Discussing Exercise Sheet 4 (Preprocessing) and 3 (SDVSTP competition), [Release of Exercise Sheet 5 (Parallel SAT)](exercises/ex5.pdf) _[NRL+DS]_
* Tuesday, July 14: E6 - Discussing Exercise Sheet 5 (Parallel SAT) ~~and 4 (SDVSTPP competition)~~, [Release of Exercise Sheet 6 (Proofs, SMT)](exercises/ex6.pdf) _[DS]_
* Tuesday, July 28: E7 - Discussing Exercise Sheet 6 (Proofs, SMT) and 4/5 (SDVSTPP and Clause sharing competition), Exam questions

## Competition Results
* E1 [Graph-Coloring](exercises/competitions/ex1-coloring.pdf) [NRL]
* E2 [Local Search](exercises/competitions/ex2-localsearch.pdf) [NRL]
* E3 [SDVSTP](exercises/competitions/sheet3-sdvstp-withkarl3.pdf) [NRL]  (updated 03.07.2026)
 

## Code

* **Tuesday, May 5**: [E0 - Pigeon Hole Principle, Cardinality Contraint Encodings, Incremental SAT Solving](https://github.com/satlecture/kit2026/blob/main/code/src/phole.cc) _[AI]_
