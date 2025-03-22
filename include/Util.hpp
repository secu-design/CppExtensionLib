#pragma once


namespace ext
{
    // narrow_cast(): a searchable way to do narrowing casts of values (Adopted from gsl::narrow_cast)
    template <class T, class U>
    constexpr T narrow_cast(U&& u) noexcept
    {
        return static_cast<T>(std::forward<U>(u));
    }

}   // namespace ext
