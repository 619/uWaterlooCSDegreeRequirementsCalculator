//Copyright 2020 Bobby Zhang

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//Changelog
//Format:
//Version: X.X
//Date: DD/MM/YYYY
//Changes: ....

//Version: 1.0
//Date: 16/01/2020
//Changes: Program created.

#include "coursecalc.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	cout << endl;
	cout << endl;

	cout << "----- (☞ﾟヮﾟ)☞ CS DEGREE COURSE REQUIREMENTS CALCULATOR ☜(ﾟヮﾟ☜) ----" << endl;
	cout << endl;
	cout << "version 1.0" << endl;
	cout << "*Does not yet work for CS Options*" << endl;
	cout << endl;
	cout << "1. Download unofficial transcript." << endl;
	cout << endl;
	cout << "2. Open the pdf, and click somewhere on the page." << endl;
	cout << endl;
	cout << "3. PC: CTRL+A to select all, then CTRL+C to copy." << endl;
	cout << "3. MAC: CMD+A to select all, then CMD+C to copy." << endl;
	cout << endl;
	cout << "4. Paste below." << endl;
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;

	bool cs11345 = false;
	bool cs1346 = false;
	bool cs240 = false;
	bool cs241 = false;
	bool cs245 = false;
	bool cs246 = false;
	bool cs251 = false;
	bool cs341 = false;
	bool cs350 = false;
	bool csupper = false;
	bool math1345 = false;
	bool math1346 = false;
	bool math12347 = false;
	bool math12348 = false;
	bool math2349 = false;
	bool stat2340 = false;
	bool stat2341 = false;

	double electives = 0;
	double nonmath = 0;
	double humreq = 0;
	double ssreq = 0;
	double psreq = 0;
	double pasreq = 0;
	double cs300s = 0;
	double cs400s = 0;
	double communication1 = 0;
	double communication2 = 0;

	string input;
	//Parse line by line until there are no more lines
	while(getline(cin, input)) {
		if (input == "End of Undergraduate Unofficial Transcript") {
			break;
		}
		stringstream sst(input);
		string token;
		//Parse tokens one by one until there are no more tokens
		while (sst >> token) {
			//Case for humanities courses
			if (find(hum.begin(), hum.end(), token) != hum.end()) {
				//Communications list 1 and 2
				string courseno;
				sst >> courseno;
				if (token == "SPCOM") {
					if (courseno == "100" || courseno == "223") {
						if (communication1) {
							humreq += 0.5;
						} else {
						communication1 = true;
						}
					} else if (courseno == "225" || courseno == "227" || courseno == "228") {
						if (communication2) {
							humreq += 0.5;
						} else {
						communication2 = true;
						humreq += 0.5;
						}
					} else {
						humreq += 0.5;	
					}
				} else if (token == "ENGL") {
					if (courseno == "129R" || courseno == "109") {
						if (communication1) {
							humreq += 0.5;
						} else {
						communication1 = true;
						}
					} else if (courseno == "108B" || courseno == "108D" || courseno == "119" || courseno == "208B" || courseno == "209" || courseno == "210E" || courseno == "210E" || courseno == "210F" || courseno == "378") {
						if (communication2) {
							humreq += 0.5;
						} else {
						communication2 = true;
						humreq += 0.5;
						}
					} else {
						humreq += 0.5;
					}
				} else  {
					humreq += 0.5;
				}
				if (nonmath >= 5.0) {
					
					electives += 0.5;
					cout << "electives: " << electives << endl;
				} else  {
					nonmath += 0.5;
				}
				//Case for social sciences courses
			} else if (find(ss.begin(), ss.end(), token) != ss.end()) {
				ssreq = ssreq + 0.5;
				if (nonmath >= 5.0) {
                                        electives += 0.5;
					cout << "electives: " << electives << endl;
                                } else  {
                                        nonmath += 0.5;
                                }
				//Case for physical sciences courses
			} else if (find(ps.begin(), ps.end(), token) != ps.end()) {
				psreq = psreq + 0.5;
				if (nonmath >= 5.0) {
                                        electives += 0.5;
					cout << "electives: " << electives << endl;
                                } else  {
                                        nonmath += 0.5;
                                }
				//Case for pure and applied Sciences
			} else if (find(pas.begin(), pas.end(), token) != pas.end()) {
				pasreq = pasreq + 0.5;
				if (nonmath >= 5.0) {
                                        electives += 0.5;
					cout << "electives: " << electives << endl;
                                } else  {
                                        nonmath += 0.5;
                                }
				//Case for CS courses
			} else if ( token == "CS" ) {
				string courseno;
				sst >> courseno;
				if (courseno == "115") {
					if (cs11345 == true) {
						electives += 0.5;
						cout << "electives: " << electives << endl;
					} else {
					cs11345 = true;
					}
				} else if (courseno == "135") {
					if (cs11345 == true) {
                                                electives += 0.5;
						cout << "electives: " << electives << endl;
                                        } else {
                                        cs11345 = true;
                                        }
				} else if (courseno == "145") {
					if (cs11345 == true) {
                                                electives += 0.5;
                                        } else {
                                        cs11345 = true;
                                        }
				} else if (courseno == "136") {
					if (cs1346 == true) {
                                                electives += 0.5;
                                        } else {
                                        cs1346 = true;
                                        }
				} else if (courseno == "146") {
					if (cs1346 == true) {
                                                electives += 0.5;
                                        } else {
                                        cs1346 = true;
                                        }
				} else if (courseno == "240") {
					cs240 = true;
				} else if (courseno == "241") {
					cs241 = true;
				} else if (courseno == "245") {
					cs245 = true;
				} else if (courseno == "246") {
					cs246 = true;
				} else if (courseno == "251") {
					cs251 = true;
				} else if (courseno == "341") {
					cs341 = true;
				} else if (courseno == "350") {
					cs350 = true;
				} else if (courseno == "499T") {
					if (csupper) {
						electives += 0.5;
						cout << "electives: " << electives << endl;
					} else  {
					csupper = true;
					}
				} else {
					//convert courseno to int to see if its a 300s or 400s CS course
					int course_int;
					try {
						istringstream(courseno) >> course_int;
					} catch (exception &e) {
						cout << "CS course code has a letter in it probably" << endl;

					}
					if (course_int >= 340 && course_int <= 398) {
						if (cs300s >= 1.5) {
							electives += 0.5;
						} else {
						cs300s = cs300s + 0.5;
						}
					} else if (course_int >= 440 && course_int <= 489) {
						if (cs400s >= 1.0 && csupper) {
							if (cs300s >= 1.5) {
								electives += 0.5;
							} else  {
								cs300s = cs300s + 0.5;
							}
						} else {
							if (cs400s >= 1.0) {
								csupper = true;
							} else {
						cs400s = cs400s + 0.5;
							}
						}
					} else if (course_int > 489 && course_int <= 498) {
						if (csupper) {
							electives += 0.5;
						} else {
							csupper = true;
						}
					} else if (course_int >= 600) {
						if (csupper) {  
                                                        electives += 0.5;
                                                } else {
                                                        csupper = true;
                                                }
					} else {
						electives += 0.5;
					}
				}	
				//Case for math courses
			} else if (token == "MATH") {
				string courseno;
				sst >> courseno;
				if (courseno == "135" || courseno == "145") {
					if (math1345) {
						electives += 0.5;
					} else {
						math1345 = true;
					}	
				} else if (courseno == "136" || courseno == "146") {
					if (math1346) {
						electives += 0.5;
					} else {
						math1346 = true;
					}
				} else if (courseno == "127" || courseno == "137" || courseno == "147") {
					if (math12347) {
                                                electives += 0.5;
                                        } else {
                                                math12347 = true;
                                        }
				} else if (courseno == "128" || courseno == "138" || courseno == "148") {
					if (math12348) {
                                                electives += 0.5;
                                        } else {
                                                math12348 = true;
                                        }
				} else if (courseno == "239" || courseno == "249") {
					if (math2349) {
                                                electives += 0.5;
                                        } else {
                                                math2349 = true;
                                        }
				} else {
					electives += 0.5;
				}
				//Case for stats courses
			} else if (token == "STAT") {
				string courseno;
				sst >> courseno;
				if (courseno == "230" || courseno == "240") {
					if (stat2340) {
                                        	electives += 0.5;
                                        } else {
                                                stat2340 = true;
                                        }
				} else if (courseno == "231" || courseno == "241") {
					if (stat2341) {
                                                electives += 0.5;
                                        } else {
                                                stat2341 = true;
                                        }
				} else if (courseno == "440") {
					if (csupper) {
                                                electives += 0.5;
					} else {
						csupper = true;
					}
				} else {
                                	electives += 0.5;
				}
				//Straggler courses handled below
			} else if (token == "EMLS") {
				string courseno;
				sst >> courseno;
				if (courseno == "101R" || courseno == "102R" || courseno == "129R") {
					if (communication1) {
						if (nonmath >= 5.0) {
							electives += 0.5;
						} else {
							nonmath += 0.5;
						}              
                                        } else {
                                                communication1 = true;
						if (nonmath >= 5.0) {
                                                        electives += 0.5;
                                                } else {
                                                        nonmath += 0.5;
                                                }
                                        }
				} else {
					if (nonmath >= 5.0) {
                                                electives += 0.5;
                                        } else {
                                                nonmath += 0.5;
                                        }
				}
			} else if (token == "MTHEL") {
				string courseno;
				sst >> courseno;
				if (courseno == "300") {
					communication2 = true;
					humreq += 0.5;
					if (nonmath >= 5.0) {
                                                        electives += 0.5;
                                                } else {
                                                        nonmath += 0.5;
                                                }
				} else {
					if (nonmath >= 5.0) {
						electives += 0.5;
					} else {
						nonmath += 0.5;
					}
				}
			} else if (token == "CO") {
				string courseno;
                                sst >> courseno;
                                if (courseno == "487") {
					if (csupper) {
						electives += 0.5;		
					} else {
						csupper = true;
					}
				} else {
					if (nonmath >= 5.0) {
                                                electives += 0.5;
                                        } else {
                                                nonmath += 0.5;
                                        }

				}
			}

		}
	}
		
	//Now, we print out the results
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "---------------------------- Results --------------------------------";
	cout << endl;

	
	if (!cs11345) {
		cout << "missing CS1[134]5!" << endl;
	}
	if (!cs1346) {
		cout << "missing CS1[34]6!" << endl;
	}
	if (!cs240) {
		cout << "missing CS240!" << endl;
	}
	if (!cs241) {
		cout << "missing CS241!" << endl;
	}
	if (!cs245) {
		cout << "missing CS245!" << endl;
	}
	if (!cs246) {
		cout << "missing CS246!" << endl;
	}
	if (!cs251) {
		cout << "missing CS251!" << endl;
	}
	if (!cs341) {
		cout << "missing CS341!" << endl;
	}
	if (!cs350) {
		cout << "missing CS350!" << endl;
	}
	if (!math1345) {
		cout << "missing MATH1[34]5!" << endl;
	}
	if (!math1346) {
		cout << "missing MATH1[134]6!" << endl;
	}
	if (!math12347) {
		cout << "missing MATH1[234]7!" << endl;
	}
	if (!math12348) {
		cout << "missing MATH1[234]8!" << endl;
	}
	if (!math2349) {
		cout << "missing MATH2[34]9!" << endl;
	}
	if (!stat2340) {
		cout << "missing STAT2[34]0!" << endl;
	}
	if (!stat2341) {
		cout << "missing STAT2[34]1!" << endl;
	} 
	if (!communication1) {
		cout << "missing communication list I course!" << endl;
	}
	if (!communication2) {
		cout << "missing communication list II course!" << endl;
	}
	if (nonmath < 5.0) {
		double nmremain;
                nmremain = 5.0 - nonmath;
                cout << "not enough nonmath courses, need ";
                cout << nmremain;
                cout << " more nonmath units, ";
                cout << nmremain * 2;
                cout << " more nonmath courses!" << endl;
	}
	if ((cs400s <= 1.0 && !csupper) || (cs400s + cs300s < 3.0 && !csupper) || (cs400s + cs300s < 2.5 && csupper)) {
		double cselectivesremain;
                cselectivesremain = 3 - cs400s - cs300s;
		if (csupper) {
			cselectivesremain += 0.5;
		}	
		
                cout << "not enough CS300s/CS400s courses, need ";
                cout << cselectivesremain;
                cout << " more CS300s/CS400s units, ";
                cout << cselectivesremain * 2;
                cout << " more CS300s/CS400s courses!" << endl;
		cout << "This includes the CS440-498 or CS449T or CS6xx or CS7xx or CO487 or STAT440 requirement." << endl;
	}
	if (humreq < 1.0) {
		double humremain;
		humremain = 1 - humreq;
		cout << "not enough humanities courses, need ";
		cout << humremain;
		cout << " more humanities units, ";
		cout << humremain * 2;
		cout << " more humanities courses!" << endl;
	}
	if (ssreq < 1.0) {
		double ssremain;
		ssremain = 1 - ssreq;
		cout << "not enough courses from the social sciences, need ";
		cout << ssremain;
		cout << " more social sciences units, ";
		cout << ssremain * 2;
		cout << " more social sciences courses!" << endl;

	}
	if (psreq < 0.5) {
		double psremain;
		psremain = 0.5 - psreq;
		cout << "not enough courses from the pure sciences, need ";
		cout << psremain;
		cout << " more units from the pure sciences, ";
		cout << psremain * 2;
		cout << " more courses from the pure sciences!" << endl;

	}
	if (pasreq < 0.5) {
		double pasremain;
		pasremain = 0.5 - pasreq;
		cout << "not enough courses from the pure and applied sciences, need ";
		cout << pasremain;
		cout << " more units from the pure and applied sciences, ";
		cout << pasremain * 2;
		cout << " more courses from the pure and applied sciences!" << endl;
	}
	if (electives < 4.0) {
		double eleremain;
		eleremain = 4.0 - electives;
		cout << "not enough elective courses, need ";
		cout << eleremain;
		cout << " more units from electives, ";
		cout << eleremain * 2;
		cout << " more courses from electives!" << endl;
	}
	cout << endl;
	cout << "Warnings:" << endl;
	cout << "This calculator does not check for the breadth and depth chain" << endl;
	cout << "This calculator counts failed and unusable courses" << endl;
	cout << "Extra stats courses were counted as nonmath courses" << endl;
	cout << "---------------------------------------------------------------------";
	cout << endl;
	cout << endl;
}
