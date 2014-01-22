const int ALPHA_LENGTH = 26;

enum Letter{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

//the checkfile functions//
int checkfile_pb(char filename[]);
int checkfile_rf(char filename[]);
int checkfile_rot(char filename[]);
int checkfile_pos(char filename[]);

Letter chartoletter(char let);

char lettertochar(Letter lett);

int lettercheck(char let);