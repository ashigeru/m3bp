/*
 * Copyright 2016 Fixstars Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef M3BP_SCHEDULER_THREAD_LOCAL_SCHEDULER_HPP
#define M3BP_SCHEDULER_THREAD_LOCAL_SCHEDULER_HPP

#include <memory>
#include "scheduler/physical_task_list.hpp"

namespace m3bp {

class PhysicalTask;

class ThreadLocalScheduler {

public:
	using PhysicalTaskPtr = std::shared_ptr<PhysicalTask>;

	PhysicalTaskList m_stealable_tasks;
	PhysicalTaskList m_unstealable_tasks;

public:
	ThreadLocalScheduler();

	void push_stealable_task(PhysicalTaskPtr task);
	void push_unstealable_task(PhysicalTaskPtr task);

	PhysicalTaskPtr pop_stealable_task();
	PhysicalTaskPtr pop_unstealable_task();

	PhysicalTaskPtr steal_task();

};

}

#endif

