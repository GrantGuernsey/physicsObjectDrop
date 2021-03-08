// Grant Guernsey
// This code calculates the dropping
// of a waterbaloon and sees if the friend of the 
// dropper will get hit, and if so in how muhc time

#include <iostream> 
#include <iomanip>
using namespace std;


double time1, time2;
const double cD = 0.0012, g = 32, delta_T = 0.001;
void physics()
{
  double vertDist;
  double walking_Speed;
  double walking_Distance;

  cout << "How far away is your friend(feet)? ";
  cin >> walking_Distance; 
  cout << "How fast are they walking(feet/sec)? ";
  cin >> walking_Speed;
  cout << "How high are you before dropping your balloon(feet)? ";
  cin >> vertDist;

  double velocity = 0;
  double calculated_Height = 0;
  int k;
  double tk;
  for(k=0;calculated_Height <= vertDist; k++){
    time2 = k * delta_T;
    velocity = velocity - (cD * velocity - g)*delta_T;
    calculated_Height = calculated_Height + velocity*delta_T;
  }

  time1 = walking_Distance / walking_Speed;
  cout << "It will take " << setprecision(2) << fixed << time1 
       << " seconds for them to reach the balloon point." << endl;
  cout << "It will take " << time2 
       << " seconds for your baloon to dravel to the ground." << endl;

  if(time1 <  time2){
    cout << "It is too late to drop your baloon" << endl;
  } else if(time1 == time2){
    cout << "Bingo, you hit your frined successsfully" << endl;
  } else {
    cout << "If you wait " << time1 - time2 << " seconds, you will hit them." << endl;
  }
}

int main() {
  physics();

  return 0;

}
