// Copyright (c) 2014 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#ifndef EOS_INLINE_TYPES_POLICY_MAP_H
#define EOS_INLINE_TYPES_POLICY_MAP_H

namespace eos {

inline policy_map_key_t::policy_map_key_t() :
      name_(), feature_() {
}

inline policy_map_key_t::policy_map_key_t(std::string const & name, 
                                   policy_feature_t const & feature) :
      name_(name), feature_(feature) {
}

inline std::string
policy_map_key_t::name() const {
   return name_;
}

inline void
policy_map_key_t::name_is(std::string const & name) {
   name_ = name;
}

inline policy_feature_t
policy_map_key_t::feature() const {
   return feature_;
}

inline void
policy_map_key_t::feature_is(policy_feature_t const & feature) {
   feature_ = feature;
}

inline bool
policy_map_key_t::operator==(policy_map_key_t const & other) const {
   return name_ == other.name_ &&
          feature_ == other.feature_;
}

inline bool
policy_map_key_t::operator!=(policy_map_key_t const & other) const {
   return !operator==(other);
}

inline bool
policy_map_key_t::operator<(policy_map_key_t const & other) const {
   if(name_ != other.name_) {
      return name_ < other.name_;
   } else if(feature_ != other.feature_) {
      return feature_ < other.feature_;
   }
   return false;
}

inline std::string
policy_map_key_t::to_string() const {
   std::ostringstream ss;
   ss << "policy_map_key_t(";
   ss << "name='" << name_ << "'";
   ss << ", feature=" << feature_;
   ss << ")";
   return ss.str();
}

inline std::ostream&
operator<<(std::ostream& os, const policy_map_key_t& obj) {
   os << obj.to_string();
   return os;
}



// Default constructor.
inline policy_map_action_t::policy_map_action_t() :
      action_type_(), nexthop_group_name_(), nexthops_(), dscp_(), traffic_class_() {
}

inline policy_map_action_t::policy_map_action_t(policy_action_type_t action_type) :
      action_type_(action_type), nexthop_group_name_(), nexthops_(), dscp_(), 
      traffic_class_() {
}

inline 
policy_map_action_t::~policy_map_action_t() {
   
}

inline policy_action_type_t
policy_map_action_t::action_type() const {
   return action_type_;
}

inline void
policy_map_action_t::action_type_is(policy_action_type_t action_type) {
   action_type_ = action_type;
}

inline std::string
policy_map_action_t::nexthop_group_name() const {
   return nexthop_group_name_;
}

inline void
policy_map_action_t::nexthop_group_name_is(
                                           std::string const & nexthop_group_name) {
   nexthop_group_name_ = nexthop_group_name;
}

inline std::unordered_set<ip_addr_t> const &
policy_map_action_t::nexthops() const {
   return nexthops_;
}

inline void
policy_map_action_t::nexthops_is(std::unordered_set<ip_addr_t> const & nexthops) {
   nexthops_ = nexthops;
}

inline void
policy_map_action_t::nexthop_set(ip_addr_t const & value) {
   nexthops_.insert(value);
}

inline void
policy_map_action_t::nexthop_del(ip_addr_t const & value) {
   nexthops_.erase(value);
}

inline uint8_t
policy_map_action_t::dscp() const {
   return dscp_;
}

inline void
policy_map_action_t::dscp_is(uint8_t dscp) {
   dscp_ = dscp;
}

inline uint8_t
policy_map_action_t::traffic_class() const {
   return traffic_class_;
}

inline void
policy_map_action_t::traffic_class_is(uint8_t traffic_class) {
   traffic_class_ = traffic_class;
}

inline bool
policy_map_action_t::operator==(policy_map_action_t const & other) const {
   return action_type_ == other.action_type_ &&
          nexthop_group_name_ == other.nexthop_group_name_ &&
          nexthops_ == other.nexthops_ &&
          dscp_ == other.dscp_ &&
          traffic_class_ == other.traffic_class_;
}

inline bool
policy_map_action_t::operator!=(policy_map_action_t const & other) const {
   return !operator==(other);
}

inline bool
policy_map_action_t::operator<(policy_map_action_t const & other) const {
   if(action_type_ != other.action_type_) {
      return action_type_ < other.action_type_;
   } else if(nexthop_group_name_ != other.nexthop_group_name_) {
      return nexthop_group_name_ < other.nexthop_group_name_;
   } else if(dscp_ != other.dscp_) {
      return dscp_ < other.dscp_;
   } else if(traffic_class_ != other.traffic_class_) {
      return traffic_class_ < other.traffic_class_;
   }
   return false;
}

inline std::string
policy_map_action_t::to_string() const {
   std::ostringstream ss;
   ss << "policy_map_action_t(";
   ss << "action_type=" << action_type_;
   ss << ", nexthop_group_name='" << nexthop_group_name_ << "'";
   ss << ", nexthops=" <<"'";
   bool first_nexthops = true;
   for (auto it=nexthops_.cbegin(); it!=nexthops_.cend(); ++it) {
      if (first_nexthops) {
         ss << (*it).to_string();
         first_nexthops = false;
      } else {
         ss << "," << (*it).to_string();
      }
   }
   ss << "'";
   ss << ", dscp=" << dscp_;
   ss << ", traffic_class=" << traffic_class_;
   ss << ")";
   return ss.str();
}

inline std::ostream&
operator<<(std::ostream& os, const policy_map_action_t& obj) {
   os << obj.to_string();
   return os;
}



inline policy_map_rule_t::policy_map_rule_t() :
      class_map_key_(), actions_() {
}

inline policy_map_rule_t::policy_map_rule_t(class_map_key_t const & class_map_key) :
      class_map_key_(class_map_key), actions_() {
}

inline class_map_key_t
policy_map_rule_t::class_map_key() const {
   return class_map_key_;
}

inline void
policy_map_rule_t::class_map_key_is(class_map_key_t const & class_map_key) {
   class_map_key_ = class_map_key;
}

inline std::set<policy_map_action_t> const &
policy_map_rule_t::actions() const {
   return actions_;
}

inline void
policy_map_rule_t::actions_is(std::set<policy_map_action_t> const & actions) {
   actions_ = actions;
}

inline void
policy_map_rule_t::action_set(policy_map_action_t const & value) {
   actions_.insert(value);
}

inline void
policy_map_rule_t::action_del(policy_map_action_t const & value) {
   actions_.erase(value);
}

inline void
policy_map_rule_t::action_del(policy_action_type_t action_type) {
   auto act = actions_.begin();
   while(act != actions_.end()) {
      if(act->action_type() == action_type) {
         act = actions_.erase(act);
      } else {
         ++act;
      }
   }
}

inline bool
policy_map_rule_t::operator==(policy_map_rule_t const & other) const {
   return class_map_key_ == other.class_map_key_ &&
          actions_ == other.actions_;
}

inline bool
policy_map_rule_t::operator!=(policy_map_rule_t const & other) const {
   return !operator==(other);
}

inline bool
policy_map_rule_t::operator<(policy_map_rule_t const & other) const {
   if(class_map_key_ != other.class_map_key_) {
      return class_map_key_ < other.class_map_key_;
   } else if(actions_ != other.actions_) {
      return actions_ < other.actions_;
   }
   return false;
}

inline std::string
policy_map_rule_t::to_string() const {
   std::ostringstream ss;
   ss << "policy_map_rule_t(";
   ss << "class_map_key=" << class_map_key_;
   ss << ", actions=" <<"'";
   bool first_actions = true;
   for (auto it=actions_.cbegin(); it!=actions_.cend(); ++it) {
      if (first_actions) {
         ss << (*it);
         first_actions = false;
      } else {
         ss << "," << (*it);
      }
   }
   ss << "'";
   ss << ")";
   return ss.str();
}

inline std::ostream&
operator<<(std::ostream& os, const policy_map_rule_t& obj) {
   os << obj.to_string();
   return os;
}



inline policy_map_t::policy_map_t() :
      key_(), rules_(), persistent_(false) {
}

inline policy_map_t::policy_map_t(policy_map_key_t const & key) :
      key_(key), rules_(), persistent_(false) {
}

inline policy_map_key_t
policy_map_t::key() const {
   return key_;
}

inline void
policy_map_t::key_is(policy_map_key_t const & key) {
   key_ = key;
}

inline std::map<uint32_t, policy_map_rule_t> const &
policy_map_t::rules() const {
   return rules_;
}

inline void
policy_map_t::rule_del(uint32_t key) {
   rules_.erase(key);
}

inline bool
policy_map_t::persistent() const {
   return persistent_;
}

inline void
policy_map_t::persistent_is(bool persistent) {
   persistent_ = persistent;
}

inline bool
policy_map_t::operator==(policy_map_t const & other) const {
   return key_ == other.key_ &&
          rules_ == other.rules_ &&
          persistent_ == other.persistent_;
}

inline bool
policy_map_t::operator!=(policy_map_t const & other) const {
   return !operator==(other);
}

inline bool
policy_map_t::operator<(policy_map_t const & other) const {
   if(key_ != other.key_) {
      return key_ < other.key_;
   } else if(rules_ != other.rules_) {
      return rules_ < other.rules_;
   } else if(persistent_ != other.persistent_) {
      return persistent_ < other.persistent_;
   }
   return false;
}

inline std::string
policy_map_t::to_string() const {
   std::ostringstream ss;
   ss << "policy_map_t(";
   ss << "key=" << key_;
   ss << ", rules=" <<"'";
   bool first_rules = true;
   for (auto it=rules_.cbegin(); it!=rules_.cend(); ++it) {
      if (first_rules) {
         ss << it->first << "=" << it->second;
         first_rules = false;
      } else {
         ss << "," << it->first << "=" << it->second;
      }
   }
   ss << "'";
   ss << ", persistent=" << persistent_;
   ss << ")";
   return ss.str();
}

inline std::ostream&
operator<<(std::ostream& os, const policy_map_t& obj) {
   os << obj.to_string();
   return os;
}


}

#endif // EOS_INLINE_TYPES_POLICY_MAP_H