namespace OPENXR_HPP_NAMESPACE {

//! Type traits
namespace traits {
//! Type trait associating an ObjectType enum value with its C++ type.
template <ObjectType o>
struct cpp_type;

//! Type trait associating a C++ handle wrapper type with an ObjectType enum value.
template <typename T>
struct object_type;

//! Type trait associating a C++ handle wrapper type with its C++ type.
template <typename T>
struct raw_handle;

//! Type trait identifying C++ handle wrapper types.
template <typename T>
struct is_handle : std::false_type {};

//! Alias for the raw handle type for a C++ handle wrapper.
template <typename T>
using raw_handle_t = typename raw_handle<T>::type;

}  // namespace traits

// forward declarations

//# for handle in gen.api_handles
class /*{ project_type_name(handle.name) }*/;
//# endfor

//# for op in ('<', '>', '<=', '>=', '==', '!=')
//! @brief /*{op}*/ comparison between C++ handle types.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE typename std::enable_if<traits::is_handle<Handle>::value, bool>::type operator/*{- op -}*/(
    Handle const &lhs, Handle const &rhs) {
    return lhs.get() /*{- op -}*/ rhs.get();
}
//! @brief /*{op}*/ comparison between a C++ handle type and raw handle.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(Handle const &lhs, traits::raw_handle_t<Handle> rhs) {
    return lhs.get() /*{- op -}*/ rhs;
}
//! @brief /*{op}*/ comparison between raw handle and a C++ handle type.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(traits::raw_handle_t<Handle> lhs, Handle const &rhs) {
    return lhs /*{- op -}*/ rhs.get();
}
//# endfor

//! @brief Equality comparison between a C++ handle type and nullptr: true if the handle is null.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE typename std::enable_if<traits::is_handle<Handle>::value, bool>::type operator==(Handle const &lhs,
                                                                                                   std::nullptr_t /* unused */) {
    return lhs.get() == XR_NULL_HANDLE;
}
//! @brief Equality comparison between nullptr and a C++ handle type: true if the handle is null.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE typename std::enable_if<traits::is_handle<Handle>::value, bool>::type operator==(std::nullptr_t /* unused */,
                                                                                                   Handle const &rhs) {
    return rhs.get() == XR_NULL_HANDLE;
}
//! @brief Inequality comparison between a C++ handle type and nullptr: true if the handle is not null.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE typename std::enable_if<traits::is_handle<Handle>::value, bool>::type operator!=(Handle const &lhs,
                                                                                                   std::nullptr_t /* unused */) {
    return lhs.get() != XR_NULL_HANDLE;
}
//! @brief Inequality comparison between nullptr and a C++ handle type: true if the handle is not null.
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE typename std::enable_if<traits::is_handle<Handle>::value, bool>::type operator!=(std::nullptr_t /* unused */,
                                                                                                   Handle const &rhs) {
    return rhs.get() != XR_NULL_HANDLE;
}

//! @brief Free function accessor for the raw handle in a a C++ handle type
template <typename Handle>
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE traits::raw_handle_t<Handle> get(Handle const &h) {
    return h.get();
}

/*% macro shared_comments(cur_cmd, method) -%*/
//!
//! See the related specification text at /*{ make_spec_url(cur_cmd.name) }*/
/*% if not method.is_core %*/
//!
//! @note No default dispatch is provided as this is a non-core function,
//! and thus requires some dynamic dispatch class (like DispatchLoaderDynamic)
/*%- endif -%*/
/*%- endmacro -%*/

//# macro method_prototypes(cur_cmd, context)

/*{- protect_begin(cur_cmd, context) }*/
/*{- discouraged_begin(cur_cmd) }*/
//#     set method = basic_cmds[cur_cmd.name]
//#     set enhanced = enhanced_cmds[cur_cmd.name]

//## Should we hide the result-returning function in enhanced mode?
//#     set hide_simple = enhanced.masks_simple

//# if hide_simple
#ifdef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif

//! @brief /*{cur_cmd.name}*/ wrapper.
/*{ shared_comments(cur_cmd, method) }*/
template </*{ method.template_decls }*/>
/*{method.return_type}*/ /*{method.cpp_name}*/ (
    /*{ method.get_declaration_params() | join(", ")}*/) /*{method.qualifiers}*/;

//# if hide_simple
#else /* OPENXR_HPP_DISABLE_ENHANCED_MODE */
//# else
#ifndef OPENXR_HPP_DISABLE_ENHANCED_MODE
//# endif


    //# if hide_simple
    //! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode (hides basic wrapper unless OPENXR_HPP_DISABLE_ENHANCED_MODE defined).
    //# else
    //! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode.
    //# endif
    /*{ shared_comments(cur_cmd, enhanced) }*/
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params() | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# if enhanced.is_two_call
    //! @brief /*{cur_cmd.name}*/ wrapper - enhanced mode, stateful allocator for two-call result.
    /*{ shared_comments(cur_cmd, enhanced) }*/
    template </*{ enhanced.template_decls }*/>
    /*{enhanced.return_type}*/ /*{enhanced.cpp_name}*/ (
        /*{ enhanced.get_declaration_params(extras=["Allocator const& vectorAllocator"], suppress_default_dispatch_arg=true) | join(", ")}*/) /*{enhanced.qualifiers}*/;

//# endif
    //# if enhanced.is_create
#ifndef OPENXR_HPP_NO_SMART_HANDLE

    //#     set uniq = unique_cmds[cur_cmd.name]
    //! @brief /*{cur_cmd.name}*/ wrapper returning a smart handle.
    /*{ shared_comments(cur_cmd, uniq) }*/
    template </*{ uniq.template_decls }*/>
    /*{uniq.return_type}*/ /*{uniq.cpp_name}*/ (
        /*{ uniq.get_declaration_params() | join(", ")}*/) /*{uniq.qualifiers}*/;
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/
    //# endif

#endif /*OPENXR_HPP_DISABLE_ENHANCED_MODE*/

/*{ discouraged_end(cur_cmd) }*/
/*{ protect_end(cur_cmd, context) }*/
//# endmacro

/*!
 * @defgroup handles Handle types
 * @brief Wrappers for OpenXR handle types, with associated functions mapped as methods.
 * @{
 */
/*!
 * @defgroup unique_handle_aliases Aliases for UniqueHandle types
 * @brief Convenience names for specializations of UniqueHandle<>
 */
//! @}

//# for handle in gen.api_handles
//# set shortname = project_type_name(handle.name)

/*{- protect_begin(handle) }*/
#ifndef OPENXR_HPP_NO_SMART_HANDLE

namespace traits {
//! Traits associating a deleter type with handles of type /*{shortname}*/
template <typename Dispatch>
class UniqueHandleTraits</*{shortname}*/, Dispatch> {
   public:
    using deleter = ObjectDestroy<Dispatch>;
};
} //namespace traits

//! @addtogroup unique_handle_aliases
//! @{

//## TODO use DispatchLoaderDynamic for extension-provided handles!
//! Shorthand name for unique handles of type /*{shortname}*/, using a static dispatch.
using /*{'Unique' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderStatic>;
//! Shorthand name for unique handles of type /*{shortname}*/, using a dynamic dispatch.
using /*{'UniqueDynamic' + shortname}*/ = UniqueHandle</*{shortname}*/, DispatchLoaderDynamic>;
//! @}
#endif /*OPENXR_HPP_NO_SMART_HANDLE*/

//! @brief Handle class - wrapping /*{handle.name}*/
//!
//! See the related specification text at /*{ make_spec_url(handle.name) }*/
//! @ingroup handles
class /*{shortname}*/ {
   public:
    using Type = /*{ shortname }*/;
    using RawHandleType = /*{handle.name}*/;

    /*!
     * @name Constructors, assignment, and conversions
     * @{
     */
    //! Default (empty/null) constructor
    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ () : m_raw(XR_NULL_HANDLE) {}

    //! Constructor from nullptr - creates empty/null handle.
    OPENXR_HPP_CONSTEXPR /*{shortname -}*/ (std::nullptr_t /* unused */) : m_raw(XR_NULL_HANDLE) {}

    //! @brief Conversion constructor from the raw /*{handle.name}*/ type
    //!
    //! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
    OPENXR_HPP_TYPESAFE_EXPLICIT /*{shortname -}*/ (RawHandleType handle) : m_raw(handle) {}

#if defined(OPENXR_HPP_TYPESAFE_CONVERSION)
    //! @brief Assignment operator from the raw /*{handle.name}*/
    //!
    //! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
    //!
    //! Only provided if OPENXR_HPP_TYPESAFE_CONVERSION is defined (defaults to only on 64-bit).
    Type &operator=(RawHandleType handle) {
        m_raw = handle;
        return *this;
    }
#endif

    //! @brief Assignment operator from nullptr - assigns to empty/null handle.
    //!
    //! Does *not* destroy any contained non-null handle first! For that, see UniqueHandle<>.
    Type &operator=(std::nullptr_t /* unused */) {
        m_raw = XR_NULL_HANDLE;
        return *this;
    }

    //! @brief Conversion operator to the raw /*{handle.name}*/ type
    //!
    //! Explicit on 32-bit platforms by default unless OPENXR_HPP_TYPESAFE_CONVERSION is defined.
    OPENXR_HPP_CONSTEXPR OPENXR_HPP_TYPESAFE_EXPLICIT operator RawHandleType() const { return m_raw; }

    //! @}

    /*!
     * @name Validity checking
     * @{
     */
    //! Returns true in conditionals if this handle is non-null
    OPENXR_HPP_CONSTEXPR explicit operator bool() const { return m_raw != XR_NULL_HANDLE; }

    //! Negation operator: true if this handle is null
    OPENXR_HPP_CONSTEXPR bool operator!() const { return m_raw == XR_NULL_HANDLE; }
    //! @}

    /*!
     * @name Raw handle manipulation
     * @{
     */
    //! @brief "Put" function for assigning as null then getting the address of the raw pointer to pass to creation functions.
    //!
    //! e.g.
    //! ```
    //! /*{shortname}*/ yourHandle;
    //! auto result = d.xrCreate/*{shortname}*/(..., yourHandle.put()));
    //! ```
    //!
    //! See also OPENXR_HPP_NAMESPACE::put()
    RawHandleType *put() {
        m_raw = XR_NULL_HANDLE;
        return &m_raw;
    }

    //! @brief Gets the raw handle type.
    //!
    //! See also OPENXR_HPP_NAMESPACE::get()
    OPENXR_HPP_CONSTEXPR RawHandleType get() const { return m_raw; }

    //! @}

    /*!
     * @name OpenXR API calls as member functions
     * @{
     */
    //## Generate "member function" prototypes
    //# for cur_cmd in sorted_cmds if cur_cmd.params[0].type == handle.name
/*{ method_prototypes(cur_cmd, handle) }*/

//# endfor

    //! @}
   private:
    RawHandleType m_raw;
};
static_assert(sizeof(/*{ shortname }*/) == sizeof(/*{handle.name}*/), "handle and wrapper have different size!");

//! @brief Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by reference).
//!
//! e.g.
//! ```
//! /*{shortname}*/ yourHandle;
//! auto result = d.xrCreate/*{shortname}*/(..., put(yourHandle));
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{shortname}*/
OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ &h) { return h.put(); }

//! @brief Free "put" function for clearing and getting the address of the raw /*{handle.name}*/ handle in a /*{shortname}*/ (by pointer).
//!
//! e.g.
//! ```
//! void yourFunction(/*{shortname}*/* yourHandle) {
//!     auto result = d.xrCreate/*{shortname}*/(..., put(yourHandle));
//!     ....
//! }
//! ```
//!
//! Should be found by argument-dependent lookup and thus not need to have the namespace specified.
//! @relates /*{shortname}*/
OPENXR_HPP_INLINE /*{handle.name}*/ *put(/*{shortname}*/ *h) { return h->put(); }

namespace traits {
//! @brief Explicit specialization of cpp_type for /*{shortname}*/
template <>
struct cpp_type<ObjectType::/*{shortname}*/> {
    using type = /*{shortname}*/;
};
//! @brief Explicit specialization of object_type for /*{shortname}*/
template <>
struct object_type</*{shortname}*/> : std::integral_constant<ObjectType, ObjectType::/*{shortname}*/> {
};

//! @brief Explicit specialization of raw_handle for /*{shortname}*/
template <>
struct raw_handle</*{shortname}*/> {
    using type = /*{handle.name}*/;
};

template <>
struct is_handle</*{shortname}*/> : std::true_type {};
} // namespace traits

/*{- protect_end(handle) }*/

//# endfor

//## Generate free-function prototypes
/*!
 * @defgroup api_free_functions OpenXR API free functions
 * 
 * Equivalent to the method wrappers in the handle classes,
 * but for the few functions that don't take (or don't require)
 * a handle as their first argument.
 * @{
 */
// Forward declarations - implementations at the bottom of the file

//# for cur_cmd in sorted_cmds if not cur_cmd.handle
/*{ method_prototypes(cur_cmd, none) }*/
//# endfor

//! @}

}  // namespace OPENXR_HPP_NAMESPACE
