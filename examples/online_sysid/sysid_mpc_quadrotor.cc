#include <gflags/gflags.h>

#include "drake/common/is_approx_equal_abstol.h"
#include "drake/examples/quadrotor/quadrotor_geometry.h"
#include "drake/examples/quadrotor/quadrotor_plant.h"
#include "drake/geometry/drake_visualizer.h"
#include "drake/lcm/drake_lcm.h"
#include "drake/systems/analysis/simulator.h"
#include "drake/systems/framework/diagram.h"
#include "drake/systems/framework/diagram_builder.h"

DEFINE_double(simulation_real_time_rate, 1.0, "Real time rate");
DEFINE_double(trial_duration, 7.0, "Duration of execution of each trial");
DEFINE_double(time_step, 0.25, "Time in seconds of timestep for control");
DEFINE_double(time_horizon, 2.5, "Time in seconds for control horizon");

namespace drake {

using systems::DiagramBuilder;
using systems::Simulator;
using systems::Context;
using systems::ContinuousState;
using systems::VectorBase;

namespace examples {
namespace online_sysid {
namespace {

int do_main() {
  lcm::DrakeLcm lcm;

  int steps = (int) (FLAGS_trial_duration / FLAGS_time_step);

  DiagramBuilder<double> builder;

  // real quadrotor, simulate by one step each time
  // run mpc on incorrect model and feed controls into real_quadrotor
  // get new state and update mpc-model parameters using least squares algorithm of choice for next step simulation
  auto real_quadrotor = builder.AddSystem<QuadrotorPlant<double>>();
  real_quadrotor->set_name("real_quadrotor");

  for (int i = 0; i < steps; i++) {
    // TODO(kzqiu): construct a new linear MPC controller and Quadrotor Plant with current estimated parameters
  }
  
  return 0;
}

} // namespace
} // namespace online_sysid
} // namespace examples
} // namespace drake

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  return drake::examples::online_sysid::do_main();
}
