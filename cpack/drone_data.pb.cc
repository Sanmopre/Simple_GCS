// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: drone_data.proto

#include "drone_data.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class DroneDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<DroneData> _instance;
} _DroneData_default_instance_;
static void InitDefaultsscc_info_DroneData_drone_5fdata_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_DroneData_default_instance_;
    new (ptr) ::DroneData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::DroneData::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_DroneData_drone_5fdata_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_DroneData_drone_5fdata_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_drone_5fdata_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_drone_5fdata_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_drone_5fdata_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_drone_5fdata_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::DroneData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::DroneData, altitude_),
  PROTOBUF_FIELD_OFFSET(::DroneData, speed_),
  PROTOBUF_FIELD_OFFSET(::DroneData, vertical_speed_),
  PROTOBUF_FIELD_OFFSET(::DroneData, latitude_),
  PROTOBUF_FIELD_OFFSET(::DroneData, longitude_),
  PROTOBUF_FIELD_OFFSET(::DroneData, fuel_),
  PROTOBUF_FIELD_OFFSET(::DroneData, temperature_engine_1_),
  PROTOBUF_FIELD_OFFSET(::DroneData, temperature_engine_2_),
  PROTOBUF_FIELD_OFFSET(::DroneData, rpm_engine_1_),
  PROTOBUF_FIELD_OFFSET(::DroneData, rpm_engine_2_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::DroneData)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_DroneData_default_instance_),
};

const char descriptor_table_protodef_drone_5fdata_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020drone_data.proto\"\337\001\n\tDroneData\022\020\n\010alti"
  "tude\030\001 \001(\005\022\r\n\005speed\030\002 \001(\002\022\026\n\016vertical_sp"
  "eed\030\003 \001(\002\022\020\n\010latitude\030\004 \001(\002\022\021\n\tlongitude"
  "\030\005 \001(\002\022\014\n\004fuel\030\006 \001(\002\022\034\n\024temperature_engi"
  "ne_1\030\007 \001(\002\022\034\n\024temperature_engine_2\030\010 \001(\002"
  "\022\024\n\014rpm_engine_1\030\t \001(\005\022\024\n\014rpm_engine_2\030\n"
  " \001(\005b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_drone_5fdata_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_drone_5fdata_2eproto_sccs[1] = {
  &scc_info_DroneData_drone_5fdata_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_drone_5fdata_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_drone_5fdata_2eproto = {
  false, false, descriptor_table_protodef_drone_5fdata_2eproto, "drone_data.proto", 252,
  &descriptor_table_drone_5fdata_2eproto_once, descriptor_table_drone_5fdata_2eproto_sccs, descriptor_table_drone_5fdata_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_drone_5fdata_2eproto::offsets,
  file_level_metadata_drone_5fdata_2eproto, 1, file_level_enum_descriptors_drone_5fdata_2eproto, file_level_service_descriptors_drone_5fdata_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_drone_5fdata_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_drone_5fdata_2eproto)), true);

// ===================================================================

void DroneData::InitAsDefaultInstance() {
}
class DroneData::_Internal {
 public:
};

DroneData::DroneData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:DroneData)
}
DroneData::DroneData(const DroneData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&altitude_, &from.altitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&rpm_engine_2_) -
    reinterpret_cast<char*>(&altitude_)) + sizeof(rpm_engine_2_));
  // @@protoc_insertion_point(copy_constructor:DroneData)
}

void DroneData::SharedCtor() {
  ::memset(&altitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rpm_engine_2_) -
      reinterpret_cast<char*>(&altitude_)) + sizeof(rpm_engine_2_));
}

DroneData::~DroneData() {
  // @@protoc_insertion_point(destructor:DroneData)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void DroneData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void DroneData::ArenaDtor(void* object) {
  DroneData* _this = reinterpret_cast< DroneData* >(object);
  (void)_this;
}
void DroneData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DroneData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const DroneData& DroneData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_DroneData_drone_5fdata_2eproto.base);
  return *internal_default_instance();
}


void DroneData::Clear() {
// @@protoc_insertion_point(message_clear_start:DroneData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&altitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&rpm_engine_2_) -
      reinterpret_cast<char*>(&altitude_)) + sizeof(rpm_engine_2_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DroneData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 altitude = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          altitude_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float speed = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          speed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float vertical_speed = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          vertical_speed_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float latitude = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 37)) {
          latitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float longitude = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          longitude_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float fuel = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 53)) {
          fuel_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float temperature_engine_1 = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 61)) {
          temperature_engine_1_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float temperature_engine_2 = 8;
      case 8:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 69)) {
          temperature_engine_2_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // int32 rpm_engine_1 = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          rpm_engine_1_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 rpm_engine_2 = 10;
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          rpm_engine_2_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DroneData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:DroneData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 altitude = 1;
  if (this->altitude() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_altitude(), target);
  }

  // float speed = 2;
  if (!(this->speed() <= 0 && this->speed() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_speed(), target);
  }

  // float vertical_speed = 3;
  if (!(this->vertical_speed() <= 0 && this->vertical_speed() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_vertical_speed(), target);
  }

  // float latitude = 4;
  if (!(this->latitude() <= 0 && this->latitude() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(4, this->_internal_latitude(), target);
  }

  // float longitude = 5;
  if (!(this->longitude() <= 0 && this->longitude() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_longitude(), target);
  }

  // float fuel = 6;
  if (!(this->fuel() <= 0 && this->fuel() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(6, this->_internal_fuel(), target);
  }

  // float temperature_engine_1 = 7;
  if (!(this->temperature_engine_1() <= 0 && this->temperature_engine_1() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(7, this->_internal_temperature_engine_1(), target);
  }

  // float temperature_engine_2 = 8;
  if (!(this->temperature_engine_2() <= 0 && this->temperature_engine_2() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(8, this->_internal_temperature_engine_2(), target);
  }

  // int32 rpm_engine_1 = 9;
  if (this->rpm_engine_1() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(9, this->_internal_rpm_engine_1(), target);
  }

  // int32 rpm_engine_2 = 10;
  if (this->rpm_engine_2() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(10, this->_internal_rpm_engine_2(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:DroneData)
  return target;
}

size_t DroneData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:DroneData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 altitude = 1;
  if (this->altitude() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_altitude());
  }

  // float speed = 2;
  if (!(this->speed() <= 0 && this->speed() >= 0)) {
    total_size += 1 + 4;
  }

  // float vertical_speed = 3;
  if (!(this->vertical_speed() <= 0 && this->vertical_speed() >= 0)) {
    total_size += 1 + 4;
  }

  // float latitude = 4;
  if (!(this->latitude() <= 0 && this->latitude() >= 0)) {
    total_size += 1 + 4;
  }

  // float longitude = 5;
  if (!(this->longitude() <= 0 && this->longitude() >= 0)) {
    total_size += 1 + 4;
  }

  // float fuel = 6;
  if (!(this->fuel() <= 0 && this->fuel() >= 0)) {
    total_size += 1 + 4;
  }

  // float temperature_engine_1 = 7;
  if (!(this->temperature_engine_1() <= 0 && this->temperature_engine_1() >= 0)) {
    total_size += 1 + 4;
  }

  // float temperature_engine_2 = 8;
  if (!(this->temperature_engine_2() <= 0 && this->temperature_engine_2() >= 0)) {
    total_size += 1 + 4;
  }

  // int32 rpm_engine_1 = 9;
  if (this->rpm_engine_1() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_rpm_engine_1());
  }

  // int32 rpm_engine_2 = 10;
  if (this->rpm_engine_2() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_rpm_engine_2());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DroneData::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:DroneData)
  GOOGLE_DCHECK_NE(&from, this);
  const DroneData* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<DroneData>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:DroneData)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:DroneData)
    MergeFrom(*source);
  }
}

void DroneData::MergeFrom(const DroneData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:DroneData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.altitude() != 0) {
    _internal_set_altitude(from._internal_altitude());
  }
  if (!(from.speed() <= 0 && from.speed() >= 0)) {
    _internal_set_speed(from._internal_speed());
  }
  if (!(from.vertical_speed() <= 0 && from.vertical_speed() >= 0)) {
    _internal_set_vertical_speed(from._internal_vertical_speed());
  }
  if (!(from.latitude() <= 0 && from.latitude() >= 0)) {
    _internal_set_latitude(from._internal_latitude());
  }
  if (!(from.longitude() <= 0 && from.longitude() >= 0)) {
    _internal_set_longitude(from._internal_longitude());
  }
  if (!(from.fuel() <= 0 && from.fuel() >= 0)) {
    _internal_set_fuel(from._internal_fuel());
  }
  if (!(from.temperature_engine_1() <= 0 && from.temperature_engine_1() >= 0)) {
    _internal_set_temperature_engine_1(from._internal_temperature_engine_1());
  }
  if (!(from.temperature_engine_2() <= 0 && from.temperature_engine_2() >= 0)) {
    _internal_set_temperature_engine_2(from._internal_temperature_engine_2());
  }
  if (from.rpm_engine_1() != 0) {
    _internal_set_rpm_engine_1(from._internal_rpm_engine_1());
  }
  if (from.rpm_engine_2() != 0) {
    _internal_set_rpm_engine_2(from._internal_rpm_engine_2());
  }
}

void DroneData::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:DroneData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DroneData::CopyFrom(const DroneData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:DroneData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DroneData::IsInitialized() const {
  return true;
}

void DroneData::InternalSwap(DroneData* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(DroneData, rpm_engine_2_)
      + sizeof(DroneData::rpm_engine_2_)
      - PROTOBUF_FIELD_OFFSET(DroneData, altitude_)>(
          reinterpret_cast<char*>(&altitude_),
          reinterpret_cast<char*>(&other->altitude_));
}

::PROTOBUF_NAMESPACE_ID::Metadata DroneData::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::DroneData* Arena::CreateMaybeMessage< ::DroneData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::DroneData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
