// We'll use a string and the gzmsg command below for a brief example.
// Remove these includes if your plugin doesn't need them.
#include <string>
#include <gz/common/Console.hh>

// This header is required to register plugins. It's good practice to place it
// in the cc file, like it's done here.
#include <gz/plugin/Register.hh>

// Don't forget to include the plugin's header.
#include "ros_gz_example_gazebo/SwerveSystem.hh"

// This is required to register the plugin. Make sure the interfaces match
// what's in the header.
IGNITION_ADD_PLUGIN(
    ros_gz_example_gazebo::SwerveSystem,
    gz::sim::System,
    ros_gz_example_gazebo::SwerveSystem::ISystemConfigure,
    ros_gz_example_gazebo::SwerveSystem::ISystemPreUpdate,
    ros_gz_example_gazebo::SwerveSystem::ISystemUpdate,
    ros_gz_example_gazebo::SwerveSystem::ISystemPostUpdate
)

namespace ros_gz_example_gazebo 
{

void SwerveSystem::Configure(const gz::sim::Entity &_entity,
                const std::shared_ptr<const sdf::Element> &_element,
                gz::sim::EntityComponentManager &_ecm,
                gz::sim::EventManager &_eventManager)
{
  igndbg << "ros_gz_example_gazebo::SwerveSystem::Configure on entity: " << _entity << std::endl;
}

void SwerveSystem::PreUpdate(const gz::sim::UpdateInfo &_info,
                           gz::sim::EntityComponentManager &_ecm)
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ros_gz_example_gazebo::SwerveSystem::PreUpdate" << std::endl;
  }
}

void SwerveSystem::Update(const gz::sim::UpdateInfo &_info,
                        gz::sim::EntityComponentManager &_ecm)
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ros_gz_example_gazebo::SwerveSystem::Update" << std::endl;
  }
}

void SwerveSystem::PostUpdate(const gz::sim::UpdateInfo &_info,
                            const gz::sim::EntityComponentManager &_ecm) 
{
  if (!_info.paused && _info.iterations % 1000 == 0)
  {
    igndbg << "ros_gz_example_gazebo::SwerveSystem::PostUpdate" << std::endl;
  }
}

}  // namespace ros_gz_example_gazebo
