/* Copyright 2019 Istio Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "extensions/common/context.h"

// OpenCensus is full of unused parameters in metric_service.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "opencensus/exporters/stats/stackdriver/stackdriver_exporter.h"
#pragma GCC diagnostic pop

#include "opencensus/stats/measure.h"
#include "opencensus/stats/stats.h"
#include "opencensus/stats/tag_key.h"

namespace Extensions {
namespace Stackdriver {
namespace Metric {

// Returns Stackdriver exporter config option based on node metadata.
opencensus::exporters::stats::StackdriverOptions getStackdriverOptions(
    const wasm::common::NodeInfo& local_node_info,
    const std::string& test_monitoring_endpoint = "",
    const std::string& sts_port = "", const std::string& test_token_path = "",
    const std::string& test_root_pem_file = "");

// registers Opencensus views
void registerViews();

// Opencensus tag key functions.
opencensus::tags::TagKey requestOperationKey();
opencensus::tags::TagKey requestProtocolKey();
opencensus::tags::TagKey serviceAuthenticationPolicyKey();
opencensus::tags::TagKey meshUIDKey();
opencensus::tags::TagKey destinationServiceNameKey();
opencensus::tags::TagKey destinationServiceNamespaceKey();
opencensus::tags::TagKey destinationPortKey();
opencensus::tags::TagKey responseCodeKey();
opencensus::tags::TagKey sourcePrincipalKey();
opencensus::tags::TagKey sourceWorkloadNameKey();
opencensus::tags::TagKey sourceWorkloadNamespaceKey();
opencensus::tags::TagKey sourceOwnerKey();
opencensus::tags::TagKey destinationPrincipalKey();
opencensus::tags::TagKey destinationWorkloadNameKey();
opencensus::tags::TagKey destinationWorkloadNamespaceKey();
opencensus::tags::TagKey destinationOwnerKey();
opencensus::tags::TagKey destinationCanonicalServiceNameKey();
opencensus::tags::TagKey destinationCanonicalServiceNamespaceKey();
opencensus::tags::TagKey sourceCanonicalServiceNameKey();
opencensus::tags::TagKey sourceCanonicalServiceNamespaceKey();
opencensus::tags::TagKey destinationCanonicalRevisionKey();
opencensus::tags::TagKey sourceCanonicalRevisionKey();

// Opencensus measure functions.
opencensus::stats::MeasureInt64 serverRequestCountMeasure();
opencensus::stats::MeasureInt64 serverRequestBytesMeasure();
opencensus::stats::MeasureInt64 serverResponseBytesMeasure();
opencensus::stats::MeasureDouble serverResponseLatenciesMeasure();
opencensus::stats::MeasureInt64 clientRequestCountMeasure();
opencensus::stats::MeasureInt64 clientRequestBytesMeasure();
opencensus::stats::MeasureInt64 clientResponseBytesMeasure();
opencensus::stats::MeasureDouble clientRoundtripLatenciesMeasure();

}  // namespace Metric
}  // namespace Stackdriver
}  // namespace Extensions