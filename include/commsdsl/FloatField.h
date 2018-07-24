#pragma once

#include <utility>
#include <map>
#include <string>

#include "Field.h"
#include "Endian.h"
#include "Units.h"
#include "Protocol.h"

namespace commsdsl
{

class FloatFieldImpl;
class COMMSDSL_API FloatField : public Field
{
    using Base = Field;
public:

    enum class Type
    {
        Float,
        Double,
        NumOfValues
    };

    struct ValidRangeInfo
    {
        double m_min = 0.0;
        double m_max = 0.0;
        unsigned m_sinceVersion = 0;
        unsigned m_deprecatedSince = Protocol::notYetDeprecated();
    };
    using ValidRangesList = std::vector<ValidRangeInfo>;

    struct SpecialValueInfo
    {
        double m_value = 0;
        unsigned m_sinceVersion = 0;
        unsigned m_deprecatedSince = Protocol::notYetDeprecated();
        std::string m_description;
    };
    using SpecialValues = std::map<std::string, SpecialValueInfo>;

    explicit FloatField(const FloatFieldImpl* impl);
    explicit FloatField(Field field);

    Type type() const;
    Endian endian() const;
    double defaultValue() const;
    const ValidRangesList& validRanges() const;
    const SpecialValues& specialValues() const;
    bool validCheckVersion() const;
    Units units() const;
    unsigned displayDecimals() const;
};

inline
bool operator==(const FloatField::SpecialValueInfo& i1, const FloatField::SpecialValueInfo& i2)
{
    return (i1.m_value == i2.m_value) &&
           (i1.m_sinceVersion == i2.m_sinceVersion) &&
           (i1.m_deprecatedSince == i2.m_deprecatedSince);
}

inline
bool operator!=(const FloatField::SpecialValueInfo& i1, const FloatField::SpecialValueInfo& i2)
{
    return !(i1 == i2);
}

inline
bool operator==(const FloatField::ValidRangeInfo& i1, const FloatField::ValidRangeInfo& i2)
{
    return (i1.m_min == i2.m_min) &&
           (i1.m_max == i2.m_max) &&
           (i1.m_sinceVersion == i2.m_sinceVersion) &&
           (i1.m_deprecatedSince == i2.m_deprecatedSince);
}

inline
bool operator!=(const FloatField::ValidRangeInfo& i1, const FloatField::ValidRangeInfo& i2)
{
    return !(i1 == i2);
}

} // namespace commsdsl
