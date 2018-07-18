#ifndef PROFILE //TODO remove this?

#include <torch/torch.h>

#include "calc_pers_cuda.cuh"
#include "vr_comp_cuda.cuh"

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m)
{
    m.def("CalcPersCuda__find_merge_pairings", &CalcPersCuda::find_merge_pairings, "find_merge_pairings (CUDA)");
    m.def("CalcPersCuda__merge_columns", &CalcPersCuda::merge_columns, "merge_columns (CUDA)");
    m.def("CalcPersCuda__read_barcodes", &CalcPersCuda::read_barcodes, "read_barcodes (CUDA)");
    m.def("CalcPersCuda__calculate_persistence", &CalcPersCuda::calculate_persistence, "calculate_persistence (CUDA)");
    m.def("CalcPersCuda__my_test_f", &CalcPersCuda::my_test_f, "test function");

    m.def("VRCompCuda__vr_l1_persistence", &VRCompCuda::vr_l1_persistence, "");
    m.def("VRCompCuda__write_combinations_table_to_tensor", &VRCompCuda::write_combinations_table_to_tensor, ""),
        m.def("VRCompCuda__vr_l1_generate_calculate_persistence_args", &VRCompCuda::vr_l1_generate_calculate_persistence_args, "");

    m.def("VRCompCuda__l1_norm_distance_matrix", &VRCompCuda::l1_norm_distance_matrix, "");
    m.def("VRCompCuda__l2_norm_distance_matrix", &VRCompCuda::l2_norm_distance_matrix, "");

    pybind11::class_<VRCompCuda::PointCloud2VR>(m, "VRCompCuda__PointCloud2VR")
        .def(pybind11::init<std::function<Tensor(const Tensor &)>>())
        // .def(pybind11::init())
        // .def_readwrite("get_distance_matrix", &VRCompCuda::PointCloud2VR::get_distance_matrix)
        .def_readwrite("boundary_info_non_vertices", &VRCompCuda::PointCloud2VR::boundary_info_non_vertices)
        .def_readwrite("filtration_values_by_dim", &VRCompCuda::PointCloud2VR::filtration_values_by_dim)
        .def_readwrite("n_simplices_by_dim", &VRCompCuda::PointCloud2VR::n_simplices_by_dim)

        .def_readwrite("simplex_dimension_vector", &VRCompCuda::PointCloud2VR::simplex_dimension_vector)
        .def_readwrite("filtration_values_vector_without_vertices", &VRCompCuda::PointCloud2VR::filtration_values_vector_without_vertices)
        .def_readwrite("filtration_add_eps_hack_values", &VRCompCuda::PointCloud2VR::filtration_add_eps_hack_values)
        .def("__call__", &VRCompCuda::PointCloud2VR::operator())

        .def("init_state", &VRCompCuda::PointCloud2VR::init_state, "")
        .def("make_boundary_info_edges", &VRCompCuda::PointCloud2VR::make_boundary_info_edges, "")
        .def("make_boundary_info_non_edges", &VRCompCuda::PointCloud2VR::make_boundary_info_non_edges, "")
        .def("make_simplex_ids_compatible_within_dimensions", &VRCompCuda::PointCloud2VR::make_simplex_ids_compatible_within_dimensions, "")
        .def("make_simplex_dimension_vector", &VRCompCuda::PointCloud2VR::make_simplex_dimension_vector, "")
        .def("make_filtration_values_vector_without_vertices", &VRCompCuda::PointCloud2VR::make_filtration_values_vector_without_vertices, "")
        .def("do_filtration_add_eps_hack", &VRCompCuda::PointCloud2VR::do_filtration_add_eps_hack, "")
        // .def("", &VRCompCuda::PointCloud2VR::, "")
        ; 

    m.def("VRCompCuda__PointCloud2VR_factory", &VRCompCuda::PointCloud2VR_factory, "");
}

#endif