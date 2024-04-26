#include <gflags/gflags.h>

#include <drake/common/drake_assert.h>
#include <drake/common/text_logging_flags.h>

namespace drake {
namespace examples {
namespace sysid {
namespace {

DEFINE_string(test, "Kevin", "Test string.");

void DoMain() {
	drake::log()->info("Hello " + FLAGS_test);
}

} // namespace
} // namespace sysid
} // namespace examples
} // namespace drake

int main(int argc, char *argv[]) {
	gflags::SetUsageMessage("Hello example.");
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	drake::examples::sysid::DoMain();
	return 0;
}
