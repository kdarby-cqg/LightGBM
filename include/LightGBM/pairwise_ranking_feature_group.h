/*!
 * Copyright (c) 2023 Microsoft Corporation. All rights reserved.
 * Licensed under the MIT License. See LICENSE file in the project root for
 * license information.
 */
#ifndef LIGHTGBM_PAIRWISE_RANKING_FEATURE_GROUP_H_
#define LIGHTGBM_PAIRWISE_RANKING_FEATURE_GROUP_H_

#include <cstdio>
#include <memory>
#include <utility>
#include <vector>

#include "feature_group.h"

namespace LightGBM {

/*! \brief Using to store data and providing some operations on one feature
group*/
class PairwiseRankingFeatureGroup: public FeatureGroup {
 public:
  /*!
  * \brief Constructor
  * \param num_feature number of features of this group
  * \param bin_mappers Bin mapper for features
  * \param num_data Total number of data
  * \param is_enable_sparse True if enable sparse feature
  * \param is_first_or_second_in_pairing Mark whether features in this group belong to the first or second element in the pairing
  */

  PairwiseRankingFeatureGroup(const FeatureGroup& other, int num_original_data, const int is_first_or_second_in_pairing, int num_pairs, const std::pair<data_size_t, data_size_t>* paired_ranking_item_index_map):
    FeatureGroup(other, num_original_data), paired_ranking_item_index_map_(paired_ranking_item_index_map), num_data_(num_pairs), is_first_or_second_in_pairing_(is_first_or_second_in_pairing) {}

  /*!
   * \brief Constructor from memory when data is present
   * \param memory Pointer of memory
   * \param num_all_data Number of global data
   * \param local_used_indices Local used indices, empty means using all data
   * \param group_id Id of group
   */
  // PairwiseRankingFeatureGroup(const void* memory,
  //                             data_size_t num_all_data,
  //                             const std::vector<data_size_t>& local_used_indices,
  //                             int group_id) {
  //   // TODO(shiyu1994)
  // }

  // /*!
  //  * \brief Constructor from definition in memory (without data)
  //  * \param memory Pointer of memory
  //  * \param local_used_indices Local used indices, empty means using all data
  //  */
  // PairwiseRankingFeatureGroup(const void* memory, data_size_t num_data, int group_id): FeatureGroup(memory, num_data, group_id) {
  //   // TODO(shiyu1994)
  // }

  /*! \brief Destructor */
  ~PairwiseRankingFeatureGroup() {}

  /*!
   * \brief Load the overall definition of the feature group from binary serialized data
   * \param memory Pointer of memory
   * \param group_id Id of group
   */
  const char* LoadDefinitionFromMemory(const void* /*memory*/, int /*group_id*/) {
    // TODO(shiyu1994)
    return nullptr;
  }

  inline BinIterator* SubFeatureIterator(int /*sub_feature*/) {
    // TODO(shiyu1994)
    return nullptr;
  }

  inline void FinishLoad() {
    // TODO(shiyu1994)
  }

  inline BinIterator* FeatureGroupIterator() {
    // TODO(shiyu1994)
    return nullptr;
  }

 private:
  void CreateBinData(int num_data, bool is_multi_val, bool force_dense, bool force_sparse) override;

  /*! \brief Pairwise data index to original data indices for ranking with pairwise features  */
  const std::pair<data_size_t, data_size_t>* paired_ranking_item_index_map_;
  /*! \brief Number of pairwise data */
  data_size_t num_data_;
  /*! \brief Mark whether features in this group belong to the first or second element in the pairing */
  const int is_first_or_second_in_pairing_;
};

}  // namespace LightGBM

#endif  // LIGHTGBM_PAIRWISE_RANKING_FEATURE_GROUP_H_
